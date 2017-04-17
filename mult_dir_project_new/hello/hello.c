#include <stdio.h>

#include <hello.h>

static void _hello(int i)
{
	printf("hell from %s() in file: %s, num:%s\n", __func__, __FILE__, i);
}

int hello(void)
{
    printf("in func: %s()\n", __func__);
    _hello(100);
    return 0;
}
