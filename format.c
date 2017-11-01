#include "loadso.h"
#include <dlfcn.h>
#include <media/NdkMediaFormat.h>


typedef AMediaFormat* (*_AMediaFormat_new)();
_AMediaFormat_new _aMediaFormat_new;
AMediaFormat *AMediaFormat_new(){
	return _aMediaFormat_new();
}
typedef media_status_t (*_AMediaFormat_delete)(AMediaFormat*);
_AMediaFormat_delete _aMediaFormat_delete;
media_status_t AMediaFormat_delete(AMediaFormat* f){
	return _aMediaFormat_delete(f);
}
typedef const char* (*_AMediaFormat_toString)(AMediaFormat*);
_AMediaFormat_toString __AMediaFormat_toString;
const char* AMediaFormat_toString(AMediaFormat* f){
	return __AMediaFormat_toString(f);
}
typedef bool (*_AMediaFormat_getInt32)(AMediaFormat*, const char *name, int32_t *out);
_AMediaFormat_getInt32 __AMediaFormat_getInt32;
bool AMediaFormat_getInt32(AMediaFormat* f, const char *name, int32_t *out){
	return __AMediaFormat_getInt32(f,name,out);
}
typedef bool (*_AMediaFormat_getInt64)(AMediaFormat*, const char *name, int64_t *out);
_AMediaFormat_getInt64 __AMediaFormat_getInt64;
bool AMediaFormat_getInt64(AMediaFormat* f, const char *name, int64_t *out){
	return __AMediaFormat_getInt64(f,name,out);
}
typedef bool (*_AMediaFormat_getFloat)(AMediaFormat*, const char *name, float *out);
_AMediaFormat_getFloat __AMediaFormat_getFloat;
bool AMediaFormat_getFloat(AMediaFormat* f, const char *name, float *out){
	return __AMediaFormat_getFloat(f,name,out);
}
typedef bool (*_AMediaFormat_getBuffer)(AMediaFormat*, const char *name, void** data, size_t *size);
_AMediaFormat_getBuffer __AMediaFormat_getBuffer;
bool AMediaFormat_getBuffer(AMediaFormat* f, const char *name, void** data, size_t *size){
	return __AMediaFormat_getBuffer(f,name,data,size);
}
typedef bool (*_AMediaFormat_getString)(AMediaFormat*, const char *name, const char **out);
_AMediaFormat_getString __AMediaFormat_getString;
bool AMediaFormat_getString(AMediaFormat* f, const char *name, const char **out){
	return __AMediaFormat_getString(f,name,out);
}
typedef void (*_AMediaFormat_setInt32)(AMediaFormat*, const char* name, int32_t value);
_AMediaFormat_setInt32 __AMediaFormat_setInt32;
void AMediaFormat_setInt32(AMediaFormat* f, const char* name, int32_t value){
	__AMediaFormat_setInt32(f,name,value);
}
typedef void (*_AMediaFormat_setInt64)(AMediaFormat*, const char* name, int64_t value);
_AMediaFormat_setInt64 __AMediaFormat_setInt64;
void AMediaFormat_setInt64(AMediaFormat* f, const char* name, int64_t value){
	__AMediaFormat_setInt64(f,name,value);
}
typedef void (*_AMediaFormat_setFloat)(AMediaFormat*, const char* name, float value);
_AMediaFormat_setFloat __AMediaFormat_setFloat;
void AMediaFormat_setFloat(AMediaFormat* f, const char* name, float value){
	__AMediaFormat_setFloat(f,name,value);
}
typedef void (*_AMediaFormat_setString)(AMediaFormat*, const char* name, const char* value);
_AMediaFormat_setString __AMediaFormat_setString;
void AMediaFormat_setString(AMediaFormat* f, const char* name, const char* value){
	__AMediaFormat_setString(f,name,value);
}
typedef void (*_AMediaFormat_setBuffer)(AMediaFormat*, const char* name, void* data, size_t size);
_AMediaFormat_setBuffer __AMediaFormat_setBuffer;
void AMediaFormat_setBuffer(AMediaFormat* f, const char* name, void* data, size_t size){
	__AMediaFormat_setBuffer(f,name,data,size);
}

int loadFormat(void* handler){
	char* error = 0;
	_aMediaFormat_new = (_AMediaFormat_new)dlsym(handler, "AMediaFormat_new");
	if ((error = dlerror()) != NULL)  {
		return -1;
	}
	_aMediaFormat_delete = (_AMediaFormat_delete)dlsym(handler, "AMediaFormat_delete");
	if ((error = dlerror()) != NULL)  {
		return -2;
	}
	__AMediaFormat_toString = (_AMediaFormat_toString)dlsym(handler, "AMediaFormat_toString");
	if ((error = dlerror()) != NULL)  {
		return -3;
	}
	__AMediaFormat_getInt32 = (_AMediaFormat_getInt32)dlsym(handler, "AMediaFormat_getInt32");
	if ((error = dlerror()) != NULL)  {
		return -4;
	}
	__AMediaFormat_getInt64 = (_AMediaFormat_getInt64)dlsym(handler, "AMediaFormat_getInt64");
	if ((error = dlerror()) != NULL)  {
		return -5;
	}
	__AMediaFormat_getFloat = (_AMediaFormat_getFloat)dlsym(handler, "AMediaFormat_getFloat");
	if ((error = dlerror()) != NULL)  {
		return -6;
	}
	__AMediaFormat_getBuffer = (_AMediaFormat_getBuffer)dlsym(handler, "AMediaFormat_getBuffer");
	if ((error = dlerror()) != NULL)  {
		return -7;
	}
	__AMediaFormat_getString = (_AMediaFormat_getString)dlsym(handler, "AMediaFormat_getString");
	if ((error = dlerror()) != NULL)  {
		return -8;
	}
	__AMediaFormat_setInt32 = (_AMediaFormat_setInt32)dlsym(handler, "AMediaFormat_setInt32");
	if ((error = dlerror()) != NULL)  {
		return -9;
	}
	__AMediaFormat_setInt64 = (_AMediaFormat_setInt64)dlsym(handler, "AMediaFormat_setInt64");
	if ((error = dlerror()) != NULL)  {
		return -10;
	}
	__AMediaFormat_setFloat = (_AMediaFormat_setFloat)dlsym(handler, "AMediaFormat_setFloat");
	if ((error = dlerror()) != NULL)  {
		return -11;
	}
	__AMediaFormat_setString = (_AMediaFormat_setString)dlsym(handler, "AMediaFormat_setString");
	if ((error = dlerror()) != NULL)  {
		return -12;
	}
	__AMediaFormat_setBuffer = (_AMediaFormat_setBuffer)dlsym(handler, "AMediaFormat_setBuffer");
	if ((error = dlerror()) != NULL)  {
		return -12;
	}
	
	return 0;
}