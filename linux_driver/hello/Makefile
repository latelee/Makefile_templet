#################################################################
# (C) Copyleft 2010 2011 2013 2015 2016 2017
# by Late Lee<latelee@163.com> at www.latelee.org
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

### nothing
OFFSET=\x1b[21G   # 21 col
COLOR1=\x1b[0;32m # green
COLOR2=\x1b[1;35m # 
COLOR3=\x1b[1;31m # red
RESET=\x1b[0m

CLEAN_BEGIN=@echo -e "$(OFFSET)$(COLOR2)Cleaning up ...$(RESET)"
CLEAN_END=@echo -e "$(OFFSET)$(COLOR2)[Done.]$(RESET)"

MAKE_BEGIN=@echo -ne "$(OFFSET)$(COLOR1)Compiling ...$(RESET)"
MAKE_DONE="$(OFFSET)$(COLOR1)[Job done!]$(RESET)";
MAKE_ERR="$(OFFSET)$(COLOR3)[Oops!Error occurred]$(RESET)";
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
	KERNELDIR ?= /home/latelee/outwork/kernel
	PWD := $(shell pwd)

    
all:
	$(MAKE_BEGIN)
	@echo 
	@if \
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules;\
	then echo -e $(MAKE_DONE)\
	else \
	echo -e  $(MAKE_ERR)\
	exit 1; \
	fi
endif

clean:
	$(CLEAN_BEGIN)
	rm -rf *.cmd *.o *.ko *.mod.c *.symvers *.order *.markers \
	.tmp_versions .*.cmd *~
	$(CLEAN_END)

install:
	@echo -e "$(COLOR3)                   Note:"
	@echo -e "To install or not install,that is a question.$(RESET)"

modules:
	@echo -e "$(COLOR3)Do not need to do this.$(RESET)"

modules_install:
	@echo -e "$(COLOR3)Do not need to do this.$(RESET)"
love:
	@echo -e "$(COLOR3)To make or not to make, that is also a question.$(RESET)"

.PHONY:all clean install love modules modules_install
