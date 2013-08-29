#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/version.h>

static int hello_init(void)
{
    printk(KERN_ALERT "hello world!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "goodbye world!\n");
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("474944723@qq.com");
//MODULE_DESCRIPION("learn from ldd3");
