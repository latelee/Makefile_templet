Makefile_templet -- Makefile templet for Linux
=======================

PROJECT
=======================
files for Makefile
* Makefile：the default Makefile, for all files in ONE directory(c or c++), auto detect the target(.so or .a or binary file)
* one_dir_project：Makefile demo
* mult_dir_project：Makefile for multi directory(ref u-boot)
* mult_dir_project_new：a new version for multi directory(not u-boot)
* linux_driver：Makefile for linux driver demo

USAGE
=======================
* Just put Makefile under the project directory, and just make it.
* For more, you may want to modify head files directory, source files directory, compiler flags and the target file name.
* What to modify? see "!!!=== " in the Makefile. If you want to delete the .a or .so files, specify the name under clean.
* By default, type：make
* For more compile information, type:make V=1  (V is uppercase)
* For debug version, type: make debug=y
* For release version, type: make debug=n
* For cross compile, type：make CROSS_COMPILE=arm-linux-
* For multi directory, type：make SRC_DIR1=foo SRC_DIR2=bar SRC_DIR3=crc

NOTES
=======================
For the Linux kernel, you need to specify the .o files under Makefile.

COPYRIGHT
=======================
Copyright by Late Lee, but anyone can use it for any purporse(study or bussiness), any problems, pls let me know.

AUTHOR
=======================
Late Lee (li@latelee.org) <br>

[CST studio](http://www.latelee.org) welcome donate!

last update: <br>
2018.1.27 <br>


Makefile_templet -- Linux环境的Makefile模板
=======================

工程说明
=======================
本仓库介绍Makefile示例。
* Makefile：默认的Makefile，针对目录下所有文件(c/c++)，根据目标文件决定是库文件还是可执行文件。
* one_dir_project：单目录工程示例
* mult_dir_project：多目录工程示例(参考uboot的)
* mult_dir_project_new：由单目录工程的Makefile改造而成，区别于uboot版本
* linux_driver：linux驱动的Makefile模板及其测试示例。

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

注意事项
=======================
内核Makefile需要手动指定编译所需的文件(.o形式)，使用通配符匹配无法编译。

版权
=======================
版权所有。<br>
本目录所有文件均可用于任何目的、场合(包括学习研究及商用)，欢迎大家使用！任何问题可反馈给作者。

作者
=======================
思堂工作室 李迟(Late Lee at li@latelee.org) <br>

[迟思堂工作室](http://www.latelee.org) 欢迎赞助作者！

last update: <br>
2018.1.27 <br>
