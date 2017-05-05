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
* 默认情况下，直接在将本Makefile放到单一的工程目录下make即可。
* 根据工程实际情况，修改头文件引用目录、源码目录、编译选项(如添加动态/静态库)，以及生成文件名。
* 要修改的地方已经使用 !!!=== 做标示，另外，如果要删除生成的.a或.so，需要在clean下添加删除的文件(本模板不做.a的匹配)。
* 默认编译：make
* 详细输出编译信息：make V=1  (V为大写)
* 调试版本：make debug=y
* 非调试版本：make debug=n
* 交叉编译版本：make CROSS_COMPILE=arm-linux-
* 多目录版本：make SRC_DIR1=foo SRC_DIR2=bar SRC_DIR3=crc

声明
=======================
本程序仅限于学习交流。<br>
欢迎使用，任何问题可反馈给作者。

作者
=======================
思堂工作室 李迟(Late Lee) <br>

[迟思堂工作室](http://www.latelee.org)

last update: <br>
2017.5.5 <br>
