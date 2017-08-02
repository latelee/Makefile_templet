
#include <linux/module.h>
//#include <linux/sched.h>
//#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
    printk(KERN_WARNING "Hello world!\n");
    return 0;
}

module_init(hello_init);
