#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for lib(libxxx.a)
# You just need to change library name and source file(s)
#

include $(TOPDIR)/config.mk

# here you can set your own flags
CFLAGS += -D_A_

# static library name
LIB = $(obj)libfoo.a

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := 
SRC_CPP := foobar.cpp

# object file(s)
OBJ_C   := $(addprefix $(obj),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj),$(patsubst %.cpp,%.o,$(SRC_CPP)))

all: $(obj).depend $(LIB)

$(LIB): $(OBJ_C) $(OBJ_CPP)
	@echo "Generating static library: " $(notdir $@)
	@$(AR) $(ARFLAGS) $@ $^

clean:
	@echo "Cleaning..."
	@$(RM) $(OBJ_C) $(OBJ_CPP) $(LIB) *.bak *~ *.d *.o $(obj).depend

.PHONY: all clean

#########################################################################

include $(TOPDIR)/rules.mk

sinclude $(obj).depend

#########################################################################
