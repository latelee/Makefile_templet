# (C) Copyleft 2011 2012 2013 2014 2015 2016 2017 2018
# Late Lee(li@latelee.org) from http://www.latelee.org
# 
# A simple Makefile for *ONE* project(c or/and cpp file) in *ONE* or *MORE* directory
#
# note: 
# you can put head file(s) in 'include' directory, so it looks 
# a little neat.
#
# usage: 
#        $ make
#        $ make V=1     # verbose ouput
#        $ make CROSS_COMPILE=arm-arago-linux-gnueabi-  # cross compile for ARM, etc.
#        $ make debug=y # debug
#
# log
#       2013-05-14 sth about debug...
#       2016-02-29 sth for c/c++ multi diretory
#       2017-04-17 -s for .a/.so if no debug
#       2017-05-05 Add V for verbose ouput
###############################################################################

# !!!=== version information
VER_MAJOR ?= 0
VER_MINOR ?= 1
# !!!=== version head file
VER_FILE ?= inc/version.h

# !!!=== release or not (R=1 means release)
R ?= 0

# !!!===
# version script
VER_SCRIPT ?= ./generate_version.sh

# !!!=== cross compile...
CROSS_COMPILE ?= 

MKDIR_P ?= mkdir -p

CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR  = $(CROSS_COMPILE)ar

# !!!===
# in case all .c/.cpp need g++...
# CC = $(CXX)

ARFLAGS = -cr
RM     = -rm -rf
MAKE   = make

CFLAGS  = 
LDFLAGS = 
DEFS    =
LIBS    =

# !!!===
# target executable file or .a or .so
target = a.out

# !!!===
# compile flags
CFLAGS += -Wall -Wfatal-errors -MMD

# !!!=== pkg-config here
#CFLAGS += $(shell pkg-config --cflags --libs glib-2.0 gattlib)
#LDFLAGS += $(shell pkg-config --cflags --libs glib-2.0 gattlib)

#****************************************************************************
# debug can be set to y to include debugging info, or n otherwise
debug  = y

#****************************************************************************

ifeq ($(debug), y)
    CFLAGS += -ggdb -rdynamic
else
    CFLAGS += -O2 -s
endif

# !!!===
# Macros define here
DEFS    += -DJIMKENT

CFLAGS  += $(DEFS)
CXXFLAGS = $(CFLAGS)

LIBS    += 

LDFLAGS += $(LIBS)

# !!!===
# include head file directory here
INC = ./include ./inc
# or try this
#INC := $(shell find $(INC) -type d)

# !!!===
# build directory
BUILD_DIR ?= #./build/

# !!!===
# source file(s), including ALL c file(s) or cpp file(s)
# just need the directory.
SRC_DIRS = . foo bar crc hello
# or try this
#SRC_DIRS = ./ 
#SRC_DIRS += ../outbox

# !!!===
# gcc/g++ compile flags
CFLAGS += $(INCDIRS)
CXXFLAGS += -std=c++11

# !!!===
# gcc/g++ link flags
LDFLAGS += -lpthread -lrt

DYNC_FLAGS += -fpic -shared

INCDIRS := $(addprefix -I, $(INC))

SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name '*.cpp' -or -name '*.c' | grep -v main.cpp)
#SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o, $(patsubst %.cpp,$(BUILD_DIR)%.o, $(SRCS))) 

DEPS := $(OBJS:.o=.d)

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

###############################################################################

# internal lib name, just ignore it
libtarget=libfoobar.a

all: $(VER_FILE) $(BUILD_DIR)$(target)

$(VER_FILE): 
	@echo "building version..."
	@chmod +x $(VER_SCRIPT); sh $(VER_SCRIPT) $(VER_FILE) $(VER_MAJOR) $(VER_MINOR) $(R)

# generate target, we need main.o here
$(BUILD_DIR)$(target): $(BUILD_DIR)$(libtarget) main.o
	@$(NQ) "Generating executable file..." $(notdir $(target))
	$(Q)$(CXX) $(CXXFLAGS) $^ -o $(target) $(BUILD_DIR)$(libtarget) $(LDFLAGS)
	@rm -rf $(BUILD_DIR)$(libtarget)

$(BUILD_DIR)$(libtarget): $(OBJS)
ifeq ($(suffix $(libtarget)), .so)
	@$(NQ) "Generating dynamic lib file..." $(notdir $(libtarget))
	$(Q)$(CXX) $^ $(LDFLAGS) $(DYNC_FLAGS) -o $(libtarget)
else ifeq ($(suffix $(libtarget)), .a)
	@$(NQ) "Generating static lib file..." $(notdir $(libtarget))
	$(Q)$(AR) $(ARFLAGS) -o $(libtarget) $^
else
	@$(NQ) "Generating executable file..." $(notdir $(libtarget))
	$(Q)$(CXX) $(LDFLAGS) $^ -o $(libtarget)
endif

# make all .c or .cpp
$(BUILD_DIR)%.o: %.c
	@$(MKDIR_P) $(dir $@)
	@$(NQ) "Compiling: " $(addsuffix .c, $(basename $(notdir $@)))
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)%.o: %.cpp
	@$(MKDIR_P) $(dir $@)
	@$(NQ) "Compiling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	$(Q)$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(NQ) "Cleaning..."
	$(Q)$(RM) $(OBJS) $(target) $(DEPS)
# delete build directory if needed
ifneq ($(BUILD_DIR),)
	$(Q)$(RM) $(BUILD_DIR)
endif
# use 'grep -v soapC.o' to skip the file
	@find . -iname '*.o' -o -iname '*.bak' -o -iname '*.d' | xargs rm -f

.PHONY: all clean

-include $(DEPS)