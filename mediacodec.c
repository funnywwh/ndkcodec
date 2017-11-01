#include <dlfcn.h>
#include "mediacodec.h"



typedef AMediaCodec* (*_AMediaCodec_createCodecByName)(const char *name);
_AMediaCodec_createCodecByName createCodecByName = 0;
AMediaCodec* AMediaCodec_createCodecByName(const char *name){
	return createCodecByName(name);
}

typedef AMediaCodec* (*_AMediaCodec_createDecoderByType)(const char *name);
_AMediaCodec_createDecoderByType createDecoderByType = 0;
AMediaCodec* AMediaCodec_createDecoderByType(const char *name){
	return createCodecByName(name);
}

typedef AMediaCodec* (*_AMediaCodec_createEncoderByType)(const char *mime_type);
_AMediaCodec_createEncoderByType createEncoderByType;
AMediaCodec* AMediaCodec_createEncoderByType(const char *mime_type){
	return createEncoderByType(mime_type);
}

typedef media_status_t (*_AMediaCodec_delete)(AMediaCodec*);
_AMediaCodec_delete aMediaCodec_delete;
media_status_t AMediaCodec_delete(AMediaCodec* codec){
	return aMediaCodec_delete(codec);
}
typedef media_status_t (*_AMediaCodec_configure)(
        AMediaCodec*,
        const AMediaFormat* format,
        ANativeWindow* surface,
        AMediaCrypto *crypto,
        uint32_t flags);
_AMediaCodec_configure configure;		
media_status_t AMediaCodec_configure(
        AMediaCodec* codec,
        const AMediaFormat* format,
        ANativeWindow* surface,
        AMediaCrypto *crypto,
        uint32_t flags){
	return configure(codec,format,surface,crypto,flags);
}
		
typedef media_status_t (*_AMediaCodec_start)(AMediaCodec*);
_AMediaCodec_start start;
media_status_t AMediaCodec_start(AMediaCodec* codec){
	return start(codec);
}
typedef media_status_t (*_AMediaCodec_stop)(AMediaCodec*);
_AMediaCodec_stop stop;
media_status_t AMediaCodec_stop(AMediaCodec* codec){
	return stop(codec);
}
typedef media_status_t (*_AMediaCodec_flush)(AMediaCodec*);
_AMediaCodec_flush flush;
media_status_t AMediaCodec_flush(AMediaCodec* codec){
	return flush(codec);
}
typedef uint8_t* (*_AMediaCodec_getInputBuffer)(AMediaCodec*, size_t idx, size_t *out_size);
_AMediaCodec_getInputBuffer getInputBuffer;
uint8_t* AMediaCodec_getInputBuffer(AMediaCodec* codec, size_t idx, size_t *out_size){
	return getInputBuffer(codec,idx,out_size);
}
typedef uint8_t* (*_AMediaCodec_getOutputBuffer)(AMediaCodec*, size_t idx, size_t *out_size);
_AMediaCodec_getOutputBuffer getOutputBuffer;
uint8_t* AMediaCodec_getOutputBuffer(AMediaCodec* codec, size_t idx, size_t *out_size){
	return getOutputBuffer(codec,idx,out_size);
}
typedef ssize_t (*_AMediaCodec_dequeueInputBuffer)(AMediaCodec*, int64_t timeoutUs);
_AMediaCodec_dequeueInputBuffer dequeueInputBuffer;
ssize_t AMediaCodec_dequeueInputBuffer(AMediaCodec* codec, int64_t timeoutUs){
	return dequeueInputBuffer(codec,timeoutUs);
}
typedef media_status_t (*_AMediaCodec_queueInputBuffer)(AMediaCodec*,
        size_t idx, off_t offset, size_t size, uint64_t time, uint32_t flags);
_AMediaCodec_queueInputBuffer queueInputBuffer;
media_status_t AMediaCodec_queueInputBuffer(AMediaCodec* codec,
        size_t idx, off_t offset, size_t size, uint64_t time, uint32_t flags){
		return 	queueInputBuffer(codec,idx,offset,size,time,flags);
}
		
typedef ssize_t (*_AMediaCodec_dequeueOutputBuffer)(AMediaCodec*, AMediaCodecBufferInfo *info,
        int64_t timeoutUs);
_AMediaCodec_dequeueOutputBuffer dequeueOutputBuffer;
ssize_t AMediaCodec_dequeueOutputBuffer(AMediaCodec* codec, AMediaCodecBufferInfo *info,
        int64_t timeoutUs){
	return dequeueOutputBuffer(codec,info,timeoutUs);	
}
		
typedef AMediaFormat* (*_AMediaCodec_getOutputFormat)(AMediaCodec*);
_AMediaCodec_getOutputFormat getOutputFormat;
AMediaFormat* AMediaCodec_getOutputFormat(AMediaCodec* codec){
	return getOutputFormat(codec);
}
typedef media_status_t (*_AMediaCodec_releaseOutputBuffer)(AMediaCodec*, size_t idx, bool render);
_AMediaCodec_releaseOutputBuffer releaseOutputBuffer;
media_status_t AMediaCodec_releaseOutputBuffer(AMediaCodec* codec, size_t idx, bool render){
	return releaseOutputBuffer(codec,idx,render);
}
typedef media_status_t (*_AMediaCodec_setOutputSurface)(AMediaCodec*, ANativeWindow* surface);
_AMediaCodec_setOutputSurface setOutputSurface;
media_status_t AMediaCodec_setOutputSurface(AMediaCodec* codec, ANativeWindow* surface){
	return setOutputSurface(codec,surface);
}
typedef media_status_t (*_AMediaCodec_releaseOutputBufferAtTime)(
        AMediaCodec *mData, size_t idx, int64_t timestampNs);
_AMediaCodec_releaseOutputBufferAtTime releaseOutputBufferAtTime;		
media_status_t AMediaCodec_releaseOutputBufferAtTime(
        AMediaCodec *codec, size_t idx, int64_t timestampNs){
		return releaseOutputBufferAtTime(codec,idx,timestampNs);
}		
typedef AMediaCodecCryptoInfo* (*_AMediaCodecCryptoInfo_new)(
        int numsubsamples,
        uint8_t key[16],
        uint8_t iv[16],
        cryptoinfo_mode_t mode,
        size_t *clearbytes,
        size_t *encryptedbytes);
_AMediaCodecCryptoInfo_new aMediaCodecCryptoInfo_new;		
AMediaCodecCryptoInfo *AMediaCodecCryptoInfo_new(
        int numsubsamples,
        uint8_t key[16],
        uint8_t iv[16],
        cryptoinfo_mode_t mode,
        size_t *clearbytes,
        size_t *encryptedbytes){
	return aMediaCodecCryptoInfo_new(numsubsamples,key,iv,mode,clearbytes,encryptedbytes);
}		
typedef media_status_t (*_AMediaCodecCryptoInfo_delete)(AMediaCodecCryptoInfo*);
_AMediaCodecCryptoInfo_delete aMediaCodecCryptoInfo_delete;
media_status_t AMediaCodecCryptoInfo_delete(AMediaCodecCryptoInfo* info){
	return aMediaCodecCryptoInfo_delete(info);
}
typedef void (*_AMediaCodecCryptoInfo_setPattern)(
        AMediaCodecCryptoInfo *info,
        cryptoinfo_pattern_t *pattern);
_AMediaCodecCryptoInfo_setPattern setPattern;		
void AMediaCodecCryptoInfo_setPattern(
        AMediaCodecCryptoInfo *info,
        cryptoinfo_pattern_t *pattern){
	return 	setPattern(info,pattern);
}
		
typedef size_t (*_AMediaCodecCryptoInfo_getNumSubSamples)(AMediaCodecCryptoInfo*);
_AMediaCodecCryptoInfo_getNumSubSamples getNumSubSamples;
size_t AMediaCodecCryptoInfo_getNumSubSamples(AMediaCodecCryptoInfo* info){
	return getNumSubSamples(info);
}
typedef media_status_t (*_AMediaCodecCryptoInfo_getKey)(AMediaCodecCryptoInfo*, uint8_t *dst);
_AMediaCodecCryptoInfo_getKey getKey;
media_status_t AMediaCodecCryptoInfo_getKey(AMediaCodecCryptoInfo* info, uint8_t *dst){
	return getKey(info,dst);
}
typedef media_status_t (*_AMediaCodecCryptoInfo_getIV)(AMediaCodecCryptoInfo*, uint8_t *dst);
_AMediaCodecCryptoInfo_getIV getIV;
media_status_t AMediaCodecCryptoInfo_getIV(AMediaCodecCryptoInfo* info, uint8_t *dst){
	return getIV(info,dst);
}
typedef cryptoinfo_mode_t (*_AMediaCodecCryptoInfo_getMode)(AMediaCodecCryptoInfo*);
_AMediaCodecCryptoInfo_getMode getMode;
cryptoinfo_mode_t AMediaCodecCryptoInfo_getMode(AMediaCodecCryptoInfo* info){
	return getMode(info);
}
typedef media_status_t (*_AMediaCodecCryptoInfo_getClearBytes)(AMediaCodecCryptoInfo*, size_t *dst);
_AMediaCodecCryptoInfo_getClearBytes getClearBytes;
media_status_t AMediaCodecCryptoInfo_getClearBytes(AMediaCodecCryptoInfo* info, size_t *dst){
	return getClearBytes(info,dst);
}
typedef media_status_t (*_AMediaCodecCryptoInfo_getEncryptedBytes)(AMediaCodecCryptoInfo*, size_t *dst);
_AMediaCodecCryptoInfo_getEncryptedBytes getEncryptedBytes;
media_status_t AMediaCodecCryptoInfo_getEncryptedBytes(AMediaCodecCryptoInfo* info, size_t *dst){
	return getEncryptedBytes(info,dst);
}
		
		

int loadCodec(void* handler){
	char* error = 0;
	createCodecByName = (_AMediaCodec_createCodecByName)dlsym(handler, "AMediaCodec_createCodecByName");
	if ((error = dlerror()) != NULL)  {
		return -1;
	}
	createDecoderByType = (_AMediaCodec_createDecoderByType)dlsym(handler, "AMediaCodec_createDecoderByType");
	if ((error = dlerror()) != NULL)  {
		return -2;
	}
	createEncoderByType = (_AMediaCodec_createEncoderByType)dlsym(handler, "AMediaCodec_createEncoderByType");
	if ((error = dlerror()) != NULL)  {
		return -3;
	}
	aMediaCodec_delete = (_AMediaCodec_delete)dlsym(handler, "AMediaCodec_delete");
	if ((error = dlerror()) != NULL)  {
		return -4;
	}
	configure = (_AMediaCodec_configure)dlsym(handler, "AMediaCodec_configure");
	if ((error = dlerror()) != NULL)  {
		return -5;
	}
	start = (_AMediaCodec_start)dlsym(handler, "AMediaCodec_start");
	if ((error = dlerror()) != NULL)  {
		return -6;
	}
	stop = (_AMediaCodec_stop)dlsym(handler, "AMediaCodec_stop");
	if ((error = dlerror()) != NULL)  {
		return -7;
	}
	flush = (_AMediaCodec_flush)dlsym(handler, "AMediaCodec_flush");
	if ((error = dlerror()) != NULL)  {
		return -8;
	}
	getInputBuffer = (_AMediaCodec_getInputBuffer)dlsym(handler, "AMediaCodec_getInputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -9;
	}
	getOutputBuffer = (_AMediaCodec_getOutputBuffer)dlsym(handler, "AMediaCodec_getOutputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -10;
	}
	dequeueInputBuffer = (_AMediaCodec_dequeueInputBuffer)dlsym(handler, "AMediaCodec_dequeueInputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -11;
	}
	queueInputBuffer = (_AMediaCodec_queueInputBuffer)dlsym(handler, "AMediaCodec_queueInputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -12;
	}
	dequeueOutputBuffer = (_AMediaCodec_dequeueOutputBuffer)dlsym(handler, "AMediaCodec_dequeueOutputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -13;
	}
	getOutputFormat = (_AMediaCodec_getOutputFormat)dlsym(handler, "AMediaCodec_getOutputFormat");
	if ((error = dlerror()) != NULL)  {
		return -14;
	}
	releaseOutputBuffer = (_AMediaCodec_releaseOutputBuffer)dlsym(handler, "AMediaCodec_releaseOutputBuffer");
	if ((error = dlerror()) != NULL)  {
		return -14;
	}
	setOutputSurface = (_AMediaCodec_setOutputSurface)dlsym(handler, "AMediaCodec_setOutputSurface");
	if ((error = dlerror()) != NULL)  {
		return -15;
	}
	releaseOutputBufferAtTime = (_AMediaCodec_releaseOutputBufferAtTime)dlsym(handler, "AMediaCodec_releaseOutputBufferAtTime");
	if ((error = dlerror()) != NULL)  {
		return -16;
	}
	aMediaCodecCryptoInfo_new = (_AMediaCodecCryptoInfo_new)dlsym(handler, "AMediaCodecCryptoInfo_new");
	if ((error = dlerror()) != NULL)  {
		return -17;
	}
	aMediaCodecCryptoInfo_delete = (_AMediaCodecCryptoInfo_delete)dlsym(handler, "AMediaCodecCryptoInfo_delete");
	if ((error = dlerror()) != NULL)  {
		return -18;
	}
	setPattern = (_AMediaCodecCryptoInfo_setPattern)dlsym(handler, "AMediaCodecCryptoInfo_setPattern");
	if ((error = dlerror()) != NULL)  {
		return -19;
	}
	getNumSubSamples = (_AMediaCodecCryptoInfo_getNumSubSamples)dlsym(handler, "AMediaCodecCryptoInfo_getNumSubSamples");
	if ((error = dlerror()) != NULL)  {
		return -20;
	}
	getKey = (_AMediaCodecCryptoInfo_getKey)dlsym(handler, "AMediaCodecCryptoInfo_getKey");
	if ((error = dlerror()) != NULL)  {
		return -21;
	}
	getIV = (_AMediaCodecCryptoInfo_getIV)dlsym(handler, "AMediaCodecCryptoInfo_getIV");
	if ((error = dlerror()) != NULL)  {
		return -22;
	}
	getMode = (_AMediaCodecCryptoInfo_getMode)dlsym(handler, "AMediaCodecCryptoInfo_getMode");
	if ((error = dlerror()) != NULL)  {
		return -23;
	}
	getClearBytes = (_AMediaCodecCryptoInfo_getClearBytes)dlsym(handler, "AMediaCodecCryptoInfo_getClearBytes");
	if ((error = dlerror()) != NULL)  {
		return -24;
	}
	getEncryptedBytes = (_AMediaCodecCryptoInfo_getEncryptedBytes)dlsym(handler, "AMediaCodecCryptoInfo_getEncryptedBytes");
	if ((error = dlerror()) != NULL)  {
		return -25;
	}
	
	return 0;
}
