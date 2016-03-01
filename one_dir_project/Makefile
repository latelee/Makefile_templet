#
# (C) Copyleft 2011 2012 2013 2014 2015 2016
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for *ONE* project(c or/and cpp file) in *ONE* or "MORE" directory
#
# note: 
# you can put head file(s) in 'include' directory, so it looks 
# a little neat.
#
# usage: $ make
#        $ make debug=y
#
# log
#       2013-05-14 sth about debug...
#       2016-02-29 sth for c/c++ multi diretory
###############################################################################

# !!!=== cross compile...
CROSS_COMPILE = 

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

ARFLAGS = -cr
RM = -rm -rf
MAKE = make

CFLAGS := -Wall

#****************************************************************************
# debug can be set to y to include debugging info, or n otherwise
debug := y

#****************************************************************************

ifeq ($(debug), y)
CFLAGS += -ggdb -rdynamic
else
# if target is lib, don't need "-O2 -s" 
CFLAGS += -O2 -s
endif

# !!!===
DEFS = -DFUCK

CFLAGS += $(DEFS)

LIBS := 

LDFLAGS := $(LIBS)

# !!!===
INCDIRS := -I./

# !!!===
CFLAGS += $(INCDIRS)

# !!!===
LDFLAGS += -lpthread -lrt

# !!!===
# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_DIR = .
# SRC_FOO = foo

# ok for c/c++
SRC = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp)

# SRC+=$(wildcard $(SRC_FOO)/*.c $(SRC_FOO)/*.cpp)

# ok for c/c++
OBJ = $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(SRC))) 

# object file(s)
#OBJ_C   := $(patsubst %.c,%.o,$(SRC_C))
#OBJ_CPP := $(patsubst %.cpp,%.o,$(SRC_CPP))

# !!!===
# target executable file or .a or .so
target = a.out

# in case all .c/.cpp need g++...
# CC = $(CXX)
###############################################################################

all: $(target)

$(target): $(OBJ)
	@echo "Generating executable file..." $(notdir $(target))
	$(CXX) $(CFLAGS) $^ -o $(target) $(LDFLAGS)
#	$(AR) $(ARFLAGS) $(target) $^ 

# make all .c or .cpp
%.o: %.c
	@echo "Compiling: " $(addsuffix .c, $(basename $(notdir $@)))
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	@echo "Compiling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@$(RM) $(target)
    # use 'grep -v xxx.o' to skip the file you need
	@find . -iname '*.o' -o -iname '*.bak' -o -iname '*.d' | xargs rm -f

.PHONY: all clean
