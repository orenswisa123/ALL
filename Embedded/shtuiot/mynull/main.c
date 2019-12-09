#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/printk.h> /* for printk and pr_* APIs */
#include <linux/init.h> /* for __init, __exit */
#include <linux/device.h>  /*for dev_t major and minor*/
#include <linux/cdev.h> /*for cdev*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oren Swisa");
MODULE_DESCRIPTION("new /dev/null");
MODULE_VERSION("1.0.0");
static dev_t mynull_dev_number;
static struct class *my_class;
static struct cdev driver_object;
static struct device *my_device;


static ssize_t driver_write(struct file *instanz, const char __user *user, size_t count, loff_t *offset)
{
	*offset
 += count;
	return count;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.write  = driver_write
};
static int __init mynewnull_init(void)
{
	int ret, err=0;
	pr_info("mynull: in new null init\n");
	ret = alloc_chrdev_region(&mynull_dev_number, 0, 1, THIS_MODULE->name);
	if (ret<0) {
		pr_info("mynull: error in alloc_chrdev_region\n");
		goto err_nothing;
	}
	/*pr_info("major is = %d\n",MAJOR(mynull_dev_number));*/
	cdev_init(&driver_object, &fops);
	ret = cdev_add(&driver_object, mynull_dev_number, 1);
	if (ret<0) {
		pr_info("mynull: error in cdev_add\n");
		goto err_register;
	}
	my_class=class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class))
	{
		pr_err("mynull: failed to create class\n");
		err = PTR_ERR(my_class);
		goto err_cdev;
	}
	my_device = device_create(my_class, NULL,mynull_dev_number,NULL,"%s",THIS_MODULE->name);
	if (IS_ERR(my_device))
	{
		pr_err("mynull: failed to create device\n");
		err = PTR_ERR(my_device);
		goto err_class;
	}
	pr_info("mynull: device loaded successfuly\n");
	
	return 0;
	err_class:
		class_destroy(my_class);
	err_cdev:
		cdev_del(&driver_object);
	err_register:
		unregister_chrdev_region(mynull_dev_number, 1);
	err_nothing:
	return err;

}

static void __exit mynewnull_exit(void)
{
	pr_info("mynull: start exiting\n");
	device_destroy(my_class, mynull_dev_number);
	class_destroy(my_class);
	cdev_del(&driver_object);
	unregister_chrdev_region(mynull_dev_number, 1);
	pr_info("mynull: in new null exit\n");
}

module_init(mynewnull_init);
module_exit(mynewnull_exit);
