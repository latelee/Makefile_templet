#################################################################
# (C) Copyleft 2010 2011 2013 2015 2016 2017 2018
# by Late Lee<li@latelee.org> from www.latelee.org
# 
# A simple Makefile for linux driver
#
# make CROSS_COMPILE=arm-linux-
# usage: 
#        $ make
#        $ make V=1     # verbose ouput
#        $ make CROSS_COMPILE=arm-linux-  # cross compile for ARM, etc.
#        $ make debug=y # debug
#################################################################

CLEAN_BEGIN=@echo "Cleaning up ..."
CLEAN_END=@echo "[Done.]"

MAKE_BEGIN=@echo "Compiling ..."
MAKE_DONE="                    [Job done!]";
MAKE_ERR="                    [Oops!Error occurred]";
### nothing end

# !!!=== for cross compile
CROSS_COMPILE = arm-linux-

CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)ld


# !!!=== for debug
#DEBUG = y

ifeq ($(DEBUG), y)
	DEBFLAGS = -O -g
else
	DEBFLAGS = -O1
endif

# CFLAGS += $(DEBFLAGS) -I$(LDDINCDIR)

# !!!=== module name here
MODULE = GotoHell

SRC = $(wildcard *.c *.cpp)
OBJ = $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(SRC)))

ifeq ($(V),1)
Q=
NQ=true
else
Q=
NQ=echo
endif

# obj-m = module
# obj-y = into kernel
# foo.o -> foo.ko
ifneq ($(KERNELRELEASE), )
	obj-m := $(MODULE).o

# !!!=== your obj file(s) here
	$(MODULE)-objs := come.o on.o

else
    # !!!=== change to your linux kernel path
	#KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	KERNELDIR ?= /home/latelee/linux_ebook/linux
	PWD := $(shell pwd)

    
all:
	$(MAKE_BEGIN)
	@echo 
	@if \
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules;\
	then echo $(MAKE_DONE)\
	else \
	echo  $(MAKE_ERR)\
	exit 1; \
	fi
endif

clean:
	$(CLEAN_BEGIN)
	rm -rf *.cmd *.o *.ko *.mod.c *.symvers *.order *.markers \
	.tmp_versions .*.cmd *~
	$(CLEAN_END)

install:
	@echo "                   Note:"
	@echo "To install or not install,that is a question."

modules:
	@echo "Do not need to do this."

modules_install:
	@echo "Do not need to do this."
love:
	@echo "To make or not to make, that is also a question."

.PHONY:all clean install love modules modules_install
