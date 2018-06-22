
#include <stdio.h>
#include <string.h>

#include <foo.h>
#include <bar.h>
#include <crc.h>
#include "hello.h"

static void nogood(void)
{
    printf("no good %s.\n", "nogood");
}

int main(void)
{
    printf("hello from %s() %d.\n", __func__, HELLO);
    hello_foo();
    hello_bar();
    //print_trace(33);
    nogood();
    /////////////////////////
    int crc = 0;
    const char* buf = "voice from hell.";
    crc = crc32((unsigned char *)buf, strlen(buf));
    printf("crc: 0x%x\n", crc);
    return 0;
}