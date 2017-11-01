package ndkcodec

import (
	"errors"
	"fmt"
	"time"
)

/*
#include <stdlib.h>
#include "loadso.h"
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
*/
import "C"

import (
	"unsafe"
)

func init() {
	C.loadSym()
}

const (
	CONFIGURE_FLAG_ENCODE = 1
)
const (
	INFO_TRY_AGAIN_LATER       = C.ssize_t(-1)
	INFO_OUTPUT_FORMAT_CHANGED = C.ssize_t(-2)
)

var (
	ErrFormatChanged = fmt.Errorf("ErrFormatChanged")
)

type NdkCodec struct {
	codec        *C.AMediaCodec
	outputFormat *Format
}

func NewNdkCodec() *NdkCodec {
	o := new(NdkCodec)
	return o
}
func (this *NdkCodec) Delete() {
	if this.codec != nil {
		C.AMediaCodec_delete(this.codec)
		this.codec = nil
	}
}
func (this *NdkCodec) Start(encoder bool, width, height, framerate, bitrate int) (err error) {
	if this.codec != nil {
		return errors.New("started")
	}
	if encoder {
		cmimetype := C.CString("video/avc")
		defer C.free(unsafe.Pointer(cmimetype))
		this.codec = C.AMediaCodec_createEncoderByType(cmimetype)
		if this.codec == nil {
			return errors.New("AMediaCodec_createEncoderByType failed")
		}
		format := NewFormat()
		defer format.Delete()
		format.SetInt32(KEY_FRAME_RATE, int32(framerate))
		format.SetInt32(KEY_BIT_RATE, int32(bitrate))
		format.SetInt32(KEY_COLOR_FORMAT, int32(COLOR_FormatYUV420SemiPlanar))
		format.SetInt32(KEY_I_FRAME_INTERVAL, int32(1))

		status := C.AMediaCodec_configure(this.codec, format.format, nil, nil, CONFIGURE_FLAG_ENCODE)
		if status <= C.media_status_t(0) {
			return fmt.Errorf("AMediaCodec_configure failed:%d", status)
		}
		status = C.AMediaCodec_start(this.codec)
		if status <= C.media_status_t(0) {
			return fmt.Errorf("AMediaCodec_start failed:%d", status)
		}

	}

	return
}
func (this *NdkCodec) Stop() (err error) {
	status := C.AMediaCodec_stop(this.codec)
	if status < 0 {
		return fmt.Errorf("AMediaCodec_stop failed:%d", status)
	}
	if this.outputFormat != nil {
		this.outputFormat.Delete()
		this.outputFormat = nil
	}
	return
}
func (this *NdkCodec) QueueInputBuffer(data []byte) (err error) {
	idx := C.AMediaCodec_dequeueInputBuffer(this.codec, C.int64_t(-1))
	if idx >= 0 {
		var outsize C.size_t
		inputBuf := C.AMediaCodec_getInputBuffer(this.codec, C.size_t(idx), &outsize)
		if outsize <= 0 {
			return nil
		}
		copy(C.GoBytes(unsafe.Pointer(inputBuf), C.int(outsize)), data)
		now := int64(time.Now().Nanosecond()) / int64(time.Microsecond)
		C.AMediaCodec_queueInputBuffer(this.codec, C.size_t(idx), 0, C.size_t(len(data)), C.uint64_t(now), 0)
	}
	return
}

func (this *NdkCodec) DequeueOutputBuffer() (data []byte, err error) {
	var info C.AMediaCodecBufferInfo
	idx := C.AMediaCodec_dequeueOutputBuffer(this.codec, &info, 0)
	switch idx {
	case INFO_TRY_AGAIN_LATER:
	case INFO_OUTPUT_FORMAT_CHANGED:
		this.outputFormat.format = C.AMediaCodec_getOutputFormat(this.codec)
		return nil, ErrFormatChanged
	}
	if idx >= 0 {
		var outsize C.size_t
		outBuf := C.AMediaCodec_getOutputBuffer(this.codec, C.size_t(idx), &outsize)
		if outsize > 0 {
			data = make([]byte, int(outsize))
			copy(data, C.GoBytes(unsafe.Pointer(outBuf), C.int(outsize)))
			status := C.AMediaCodec_releaseOutputBuffer(this.codec, C.size_t(idx), false)
			if status < 0 {
				return nil, fmt.Errorf("AMediaCodec_releaseOutputBuffer failed:%d", status)
			}
		}
	}
	return
}
func (this *NdkCodec) GetOutputFormat() *Format {
	return this.outputFormat
}
