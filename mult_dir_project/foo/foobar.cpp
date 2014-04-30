#include <stdio.h>
#include <foo.h>
#include <bar.h>

// test of macro in Makefile
#if !defined (_A_) && !defined (_B_)
#error "define _A_ or _B_!!"
#endif

void foo(int i)
{
	printf("hell from %s() in file: %s, num:%d\n", __func__, __FILE__, i);
}

int hello_foo(void)
{
    printf("in func: %s()\n", __func__);
    bar(100);
    return 0;
}
