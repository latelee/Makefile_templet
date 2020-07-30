#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "debug.h"

// 处理buffer的函数，可以指定到文件或终端或其它
void foobar(const char *buffer)
{
    printf("%s", buffer);
}

handle_buffer_fn_t handle_buffer_fn = foobar;

//void (*handle_buffer_fn)(const char *buffer) = foobar;


int mysprintf_1(char *buffer, int len, const char* fmt, va_list ap)
{
     int ret = 0;

#ifdef WIN32
     ret = _vsnprintf(buffer, len, fmt, ap);
#else
    ret = vsnprintf(buffer, len, fmt, ap);
#endif
    printf("ret: %d\n", ret);
    if (ret > len - 1)
        ret = len - 1;
    /* when actual len > len, ret = -1(VS 2003) */
    else if (ret == -1)
        ret = len - 1;

    buffer[ret] = '\0';
     //buffer[len -1] = '\0';

     return ret;
}

int _myprintf(handle_buffer_fn_t fn, const char* fmt, ...)
{
    char buffer[512] = {0};
    va_list ap;
    int ret = -1;

    va_start(ap, fmt);
    ret = vsprintf(buffer, fmt, ap);
    va_end(ap);

    if (fn != NULL)
    {
        fn(buffer);
    }

    return ret;
}

int myprintf(const char* fmt, ...)
{
#if 01
    char buffer[512] = {0};
    va_list ap;
    int ret = -1;

    va_start(ap, fmt);
    ret = vsprintf(buffer, fmt, ap);
    va_end(ap);

    if (handle_buffer_fn != NULL)
    {
        handle_buffer_fn(buffer);
    }

    return ret;
#endif
    //_myprintf(foobar, fmt);
}

int mysprintf(char *buffer, int len, const char* fmt, ...)
{
    va_list ap;
     int ret = 0;

    va_start(ap, fmt);
#ifdef WIN32
     ret = _vsnprintf(buffer, len, fmt, ap);
#else
    ret = vsnprintf(buffer, len, fmt, ap);
#endif
    va_end(ap);
    if (ret > len - 1)
        ret = len - 1;
    /* 当指定长度太小时，返回-1，非实际长度(VS 2003) */
    else if (ret == -1)
        ret = len - 1;

    buffer[ret] = '\0';
    //buffer[len -1] = '\0';

     return ret;
}

void get_timestamp(char *buffer)
{
    time_t t;
    struct tm *p;
    int len;
    t = time(NULL);
    p = localtime(&t);
    /* 时间格式：[2011/11/15 12:47:34] */
    len = mysprintf(buffer, 22, "[%04d/%02d/%02d %02d:%02d:%02d]", p->tm_year+1900, p->tm_mon+1, \
        p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    buffer[len] = '\0';
}

#define DEFWIDTH 16          /* Default # chars to show per line */
#define MAXWIDTH 32          /* Maximum # of bytes per line     */

/*
输出示例，最大72字节，
0000  89 50 4e 47 0d 0a 1a 0a 00 00 00 0d 49 48 44 52  .PNG........IHDR
....
0040  70 6f 73 10 ea ff                                pos...
 
*/
void dumpfile(FILE *f, char *buffer)
{
    int     ch = '\0';          /* current character            */
    char    ascii[MAXWIDTH+3];  /* printable ascii data         */
    int     i = 0;              /* counter: # bytes processed     */
    int     ai = 0;             /* index into ascii[]           */
    int     offset = 0;         /* byte offset of line in file  */
    int     hpos = 0;           /* horizontal position counter  */
    int     linesize = DEFWIDTH;     /* # of bytes to print per line */
    int     count = 0;

    do {
        ch = getc(f);

        if (ch != EOF)
        {
            if (i++ % linesize == 0)
            {
                printf("%04x  ", offset);
                count += mysprintf(buffer+count, 10, "%04x  ", offset);
                offset += linesize;
                hpos = 6; // 4+2
            }

            ascii[ai] = (isprint (ch) || ch == ' ') ? ch : '.';
            printf("%02x ", ch);
            count += mysprintf(buffer+count, 10, "%02x ", ch);
            /* update counters and things */
            ai++;
            hpos += 3; // 2+1
        }

        /* At end-of-line or EOF, show ASCII data. */
        if (i && (ch == EOF || (i % linesize == 0)))
        {
            while (hpos < linesize * 3 + 7)
            {
                putchar(' ');
                count += mysprintf(buffer+count, 10, " ");
                hpos++;
            }
            ascii[ai] = '\0';
            printf("%s", ascii);
            count += mysprintf(buffer+count, 20, "%s", ascii);
            if (ch != EOF || (i % linesize != 0))
            {
                putchar('\n');
                count += mysprintf(buffer+count, 10, "\n");
            }
            ai = 0;          /* reset counters */
        }
    } while (ch != EOF);

}

/**
输出示例：
地址：字符十六进制 可打印字符
new buffer print: 70
0x0012FAE4: 89 50 4e 47 0d 0a 1a 0a 00 00 00 0d 49 48 44 52  .PNG........IHDR
0x0012FAF4: 00 00 00 f0 00 00 01 40 08 02 00 00 00 0d 8a 66  .......@.......f
0x0012FB04: 04 00 00 20 00 49 44 41 54 78 da ed 7d 3d 68 24  ... .IDATx..}=h$
0x0012FB14: 01 02 03 04 05 06 07 08 09 0a 0b                 ...........
*/
void dump(const char *buffer, int len)
{
    int i, j, n;
    int line = 16;
    char c;
    unsigned char* buf = (unsigned char *)buffer;    // 必须是unsigned char类型

    n = len / line;
    if (len % line)
        n++;

    for (i=0; i<n; i++)
    {
        //printf("0x%08x: ", (unsigned int)(buf+i*line)); // linux ok
        printf("0x%8p: ", buf+i*line); // windows ok
        
        for (j=0; j<line; j++)
        {
            if ((i*line+j) < len)
                printf("%02x ", buf[i*line+j]);
            else
                printf("   ");
        }

        printf(" ");
        for (j=0; j<line && (i*line+j)<len; j++)
        {
            if ((i*line+j) < len)
            {
                c = buf[i*line+j];
                printf("%c", c >= ' ' && c < '~' ? c : '.');
            }
            else
                printf("   ");
        }

        printf("\n");
    }
}

/* Print n as a binary number */
void printbitssimple(int n)
{
	unsigned int i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
}

/* Print n as a binary number */
void printbits(int n)
{
	unsigned int i, step;
    int j = 1;

	if (0 == n) { /* For simplicity's sake, I treat 0 as a special case*/
		printf("0000");
		return;
	}

	i = 1<<(sizeof(n) * 8 - 1);

	step = -1; /* Only print the relevant digits */
	step >>= 4; /* In groups of 4 */
	while (step >= n) {
		i >>= 4;
		step >>= 4;
	}

	/* At this point, i is the smallest power of two larger or equal to n */
	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;

        if ((j++ % 4) == 0)
            printf(" ");
	}
}

// 指定位数的版本
// num只支持4的倍数，非4倍数格式不对齐
// TODO：优化一下
void printbits_n(int n, int num)
{
	unsigned int i, step;
    int j = 1;
    int k = 0;
    int x = 1;

	if (0 == n) { /* For simplicity's sake, I treat 0 as a special case*/
		//printf("%s", (num)["0000 0000 0000 0000 0000 0000 0000 0000"]);
		//printf("0000");
		j = num / 4;
		while (j > 0)
		{
			printf("0000 ");
			j--;
		}
        return;
	}

	i = 1<<(sizeof(n) * 8 - 1);
    //printf("1 %x\n", i);
	step = -1; /* Only print the relevant digits */
	step >>= 4; /* In groups of 4 */
	while (step >= n) {
		i >>= 4;
		step >>= 4;
	}

    //printf("2 %x\n", i);
    k = i;
    while ((k>>=1) != 0)
    {
        x++;
    }
    //printf("x: %d\n", x);
	j = 1;
	while (x < num)
	{
		printf("0");
		if ((j++ % 4) == 0)
            printf(" ");
		x++;
	}
	j = 1;
	/* At this point, i is the smallest power of two larger or equal to n */
	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;

        if ((j++ % 4) == 0)
            printf(" ");
	}
}

void printbits_n_1(int n, int num)
{
#if 0
	unsigned int u = 1, b;
	int i;

	u = u << sizeof(int)*8 - 1;
	
	for (i = 0; i < sizeof(int)*8; i++)
	{
		b = (n << i) & u;
		printf("%d", b >> sizeof(int)*8 -1);
	}
	printf("\n");
#else
#define N 32
#define M (1<<(N-1))

	int i;
	for (i = 0; i < N && i < num; i++)
	{
		if ((i % 4) == 0)
			printf(" ");
		printf("%c", ((n&1) == 0) ? '0' : '1');
		n >>= 1;
	}
	printf("\n");
#endif
}