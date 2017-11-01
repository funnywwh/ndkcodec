#ifndef _LOAD_SO_H_
#define _LOAD_SO_H_


typedef unsigned char bool;

int loadSym();
int unloadSym();

int loadCodec(void* handler);
int loadFormat(void* handler);

#endif //_LOAD_SO_H_