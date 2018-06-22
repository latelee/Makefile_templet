
#ifndef _DEBUG_H
#define _DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

typedef void (*handle_buffer_fn_t)(const char *buffer);

int myprintf(const char* fmt, ...);
// TODO：如何调用这些函数？
int _myprintf(handle_buffer_fn_t fn, const char* fmt, ...);

void get_timestamp(char *buffer);

void dumpfile(FILE *f, char *buffer);
void dump(const char *buffer, int len);

void printbits(int n);
void printbits_n(int n, int num);

void printbits_n_1(int n, int num);

void printbitssimple(int n);

#ifdef __cplusplus
}
#endif

#endif