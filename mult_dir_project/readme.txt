仿uboot的Makefile模板。

目录架构：
.
├── bar
│   ├── bar.c
│   ├── crc.cpp
│   ├── foo.c
│   └── Makefile
├── foo
│   ├── foobar.cpp
│   ├── Makefile
│   └── not-foo.cpp
├── include
│   ├── backtrace.h
│   ├── bar.h
│   ├── crc.h
│   └── foo.h
├── main
│   ├── config.mk
│   ├── hello.h
│   ├── main.cpp
│   ├── Makefile
│   ├── mkconfig
│   └── rules.mk
└── readme.txt

4 directories, 18 files

bar、foo为子模块，main目录为主程序所在，include为头文件所在。

主Makefile与主代码同一目录，各子模块目录有子Makefile。

默认：
.o文件目录：与src同一目录的build
可执行文件：与src同一目录的bin


当前Makefile模板仅适用当前的目录层次架构，当层次更改时，不一定适用。

生成的文件：在工程同一目录下有build和bin目录。在这里是工程目录指mult_dir_project。

todo：可以把Makfile提到工程目录下一级，而不像现在的放到main目录。

Late Lee

2013-03-06