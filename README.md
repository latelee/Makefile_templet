Makefile_templet -- Linux环境的Makefile模板
=======================

工程说明
=======================
本仓库介绍Makefile示例。
* Makefile_simple：最简单的Makefile示例，针对目录下所有文件(c/c++)，根据目标文件决定是库文件还是可执行文件。
* one_dir_project：单目录工程示例
* mult_dir_project：多目录工程示例(参考uboot的)
* mult_dir_project_new：由单目录工程的Makefile改造而成，区别于uboot版本

用法
=======================
* 根据工程实际情况，修改头文件引用目录、源码目录、编译选项(如添加动态/静态库)，以及生成文件名。
* 要修改的地方已经使用 !!!=== 做标示
* 可直接运行make
* 调试版本：make debug=y
* 多目录版本：make SRC_DIR1=foo SRC_DIR2=bar SRC_DIR3=crc
* 交叉编译版本：make CROSS_COMPILE=arm-linux-

声明
=======================
本程序仅限于学习交流。<br>
欢迎使用，任何问题可反馈给作者。

作者
=======================
思堂工作室 李迟(Late Lee) <br>
2016.5.5 <br>
[迟思堂工作室](http://www.latelee.org)
