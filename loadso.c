#include "loadso.h"
#include <dlfcn.h>
static void* handler = 0;

int loadSym(){
	char* error  = 0;
	handler = dlopen("libmediandk.so",RTLD_LAZY);
	if(handler <= 0){
		return -1;
	}
	if(loadCodec(handler) < 0){
		return -2;
	}
	if(loadFormat(handler) < 0){
		return -3;
	}
	return 0;
}
int unloadSym(){
	if(handler){
		dlclose(handler);
		handler = 0;
	}
}