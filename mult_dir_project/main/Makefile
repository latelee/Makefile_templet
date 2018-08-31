#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for multi-directory
# Most idea comes from U-boot project
#

# object file directory, eg
# $ make O =../build
# BUILD_DIR = ../build
# NOTE!!! do not add "/" at the end!
BUILD_DIR := ../build

# binary file director
BIN_DIR := ../bin

OBJTREE		:= $(if $(BUILD_DIR),$(BUILD_DIR),$(CURDIR))
SRCTREE		:= $(CURDIR)
TOPDIR		:= $(SRCTREE)
LNDIR		:= $(OBJTREE)
export	TOPDIR SRCTREE OBJTREE

include $(TOPDIR)/config.mk

###############################################################################
# libs
_LIBS := ../bar/libbar.a ../foo/libfoo.a

LIBS := $(addprefix $(obj),$(_LIBS))

LDFLAGS = $(addprefix $(obj),$(subst ../,,$(_LIBS)))

# main.c in this directory, can be empty
MAIN_DIR := main/

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := $(wildcard *.c)
SRC_CPP := $(wildcard *.cpp)

# object file(s)
OBJ_C   := $(addprefix $(obj)$(MAIN_DIR),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj)$(MAIN_DIR),$(patsubst %.cpp,%.o,$(SRC_CPP)))

# mkdir MAIN_DIR
ifneq ($(MAIN_DIR),)
$(shell mkdir -p $(addprefix $(obj),$(MAIN_DIR)))
endif

ifneq ($(BIN_DIR),)
$(shell mkdir -p $(BIN_DIR))
endif

# executable file
target = $(BIN_DIR)/a.out

###############################################################################

all: config $(target)

config:
	@echo "Generating... hello.h"
	@$(MKCONFIG)

$(target): $(LIBS) exe

# make all .c or .cpp
$(obj)$(MAIN_DIR)%.o:	%.c
	@echo "Compling: " $(addsuffix .c, $(basename $(notdir $@)))
	$(CC) $(CFLAGS) -c $< -o $@

$(obj)$(MAIN_DIR)%.o:	%.cpp
	@echo "Compling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	$(CXX) $(CFLAGS) -c $< -o $@

exe: $(OBJ_CPP) $(OBJ_C)
	@echo "Generating executable file..." $(notdir $(target))
	$(CXX) $(CFLAGS) $^ -o $(target) $(LDFLAGS)

$(LIBS):
	$(MAKE) -C $(dir $(subst $(obj),,$@))

depend:
	$(MAKE) -C ../bar/ _depend

clean:
	@echo "cleaning..."
	@$(RM) $(target)
	@$(RM) hello.h
	@find $(OBJTREE) $(BIN_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' \) -print \
		| xargs rm -f
distclean:
	@echo "distcleaning..."
	@$(RM) $(target)
	@$(RM) hello.h
	@find $(OBJTREE) $(BIN_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' \) -print \
		| xargs rm -f
	@$(RM) $(obj) $(BUILD_DIR)
	@$(RM) $(BIN_DIR)

.PHONY: all clean distclean $(LIBS) exe
