package ndkcodec

/*
#include <stdlib.h>
#include "loadso.h"
#include <media/NdkMediaFormat.h>
*/
import "C"

import (
	"unsafe"
)

const (
	KEY_FRAME_RATE       = "frame-rate"
	KEY_BIT_RATE         = "bitrate"
	KEY_COLOR_FORMAT     = "color-format"
	KEY_I_FRAME_INTERVAL = "i-frame-interval"
)

const (
	COLOR_FormatYUV420SemiPlanar = 21
)

type Format struct {
	format *C.AMediaFormat
}

func NewFormat() *Format {
	o := new(Format)
	o.format = C.AMediaFormat_new()
	return o
}
func (this *Format) Delete() {
	if this.format != nil {
		C.AMediaFormat_delete(this.format)
	}
	this.format = nil
}
func (this *Format) SetInt32(name string, value int32) {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	C.AMediaFormat_setInt32(this.format, cname, C.int32_t(value))
}
func (this *Format) SetInt64(name string, value int64) {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	C.AMediaFormat_setInt64(this.format, cname, C.int64_t(value))
}
