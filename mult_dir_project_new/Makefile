# (C) Copyleft 2011 2012 2013 2014 2015 2016 2017 2018 2019 2020
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
#        $ make SRC_DIR1=foo SRC_DIR2=bar SRC_DIR3=crc
#
# log
#       2013-05-14 sth about debug...
#       2016-02-29 sth for c/c++ multi diretory
#       2017-04-17 -s for .a/.so if no debug
#       2017-05-05 Add V for verbose ouput
###############################################################################

# !!!=== cross compile...
CROSS_COMPILE ?= 

CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR  = $(CROSS_COMPILE)ar

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
CFLAGS += -Wall -Wfatal-errors

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
DEFS    += -DJIMKENT

CFLAGS  += $(DEFS)
CXXFLAGS = $(CFLAGS)

LIBS    += ./hello/libhello.a

LDFLAGS += $(LIBS)

# !!!===
INC = ./ ./inc

INCDIRS := $(addprefix -I, $(INC))

# !!!===
CFLAGS += $(INCDIRS)
CXXFLAGS += -std=c++11

# !!!===
LDFLAGS += -lpthread -lrt

DYNC_FLAGS += -fpic -shared

# !!!===
# source file(s), including c file(s) or cpp file(s)
SRC_DIRS = . foo crc bar

SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name '*.cpp' -or -name '*.c')

OBJS = $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SRCS))) 

# !!!===
# in case all .c/.cpp need g++...
# CC = $(CXX)

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

###############################################################################

all: $(target)

$(target): $(OBJS)

ifeq ($(suffix $(target)), .so)
	@$(NQ) "Generating dynamic lib file..." $(notdir $(target))
	$(Q)$(CXX) $^ $(LDFLAGS) $(DYNC_FLAGS) -o $(target)
else ifeq ($(suffix $(target)), .a)
	@$(NQ) "Generating static lib file..." $(notdir $(target))
	$(Q)$(AR) $(ARFLAGS) -o $(target) $^
else
	@$(NQ) "Generating executable file..." $(notdir $(target))
	$(Q)$(CXX) $^ $(LDFLAGS) -o $(target)
endif

# make all .c or .cpp
%.o: %.c
	@$(NQ) "Compiling: " $(addsuffix .c, $(basename $(notdir $@)))
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	@$(NQ) "Compiling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	$(Q)$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(NQ) "Cleaning..."
	$(Q)$(RM) $(target) $(OBJS)

# use 'grep -v soapC.o' to skip the file
	@find . -iname '*.o' -o -iname '*.bak' -o -iname '*.d' | xargs rm -f

.PHONY: all clean
