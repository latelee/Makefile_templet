#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for lib(libxxx.a)
# You just need to change library name and source file(s)
#

include $(TOPDIR)/config.mk

# static library name
LIB = $(obj)libbar.a

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c) or *.c, etc.
SRC_C   := bar.c foo.c 
SRC_CPP := crc.cpp

# object file(s)
OBJ_C   := $(addprefix $(obj),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj),$(patsubst %.cpp,%.o,$(SRC_CPP)))

all: $(obj).depend $(LIB)

$(LIB):  $(OBJ_C) $(OBJ_CPP)
	@echo "Generating static library: " $(notdir $@)
	@$(AR) $(ARFLAGS) $@ $^

clean:
	@echo "Cleaning..."
	@$(RM) $(LIB) $(OBJ_C) $(OBJ_CPP) *.bak *~ $(obj).depend *.o

.PHONY: all clean

#########################################################################

include $(TOPDIR)/rules.mk

sinclude $(obj).depend

#########################################################################
