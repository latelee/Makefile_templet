#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple file to specify compier and macros and flags
# and ways to compile .c & .cpp
#

# cross compile...
CROSS_COMPILE = 

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

ARFLAGS = cr
RM = -rm -rf
MAKE = make

CFLAGS = -Wall -Wfatal-errors -MM
DEBUG = y

ifeq ($(DEBUG), y)
CFLAGS += -g
DEBREL = Debug
else
CFLAGS += -O2 -s
DEBREL = Release
endif

DEFS = 

CFLAGS += $(DEFS)

LDFLAGS = $(LIBS)

INCDIRS = ../include/

CFLAGS += -I$(INCDIRS)

###############################################################################

ifneq ($(OBJTREE),$(SRCTREE))
ifeq ($(CURDIR),$(SRCTREE))
dir :=
else
dir := $(subst $(SRCTREE)/,,$(CURDIR))
endif

obj := $(if $(dir),$(OBJTREE)/$(notdir $(dir))/,$(OBJTREE)/)
src := $(if $(dir),$(SRCTREE)/$(notdir $(dir))/,$(SRCTREE)/)

$(shell mkdir -p $(obj))
else
obj :=
src :=
endif

suffix = $(notdir $(CURDIR))
export suffix

# test of shell script
MKCONFIG	:= $(SRCTREE)/mkconfig
export MKCONFIG

# export to other Makefile
export CC
export CFLAGS
export INCDIRS
export AR
export ARFLAGS
export RM

###############################################################################

# make all .c or .cpp
$(obj)%.o:	%.c
	@echo "Compling: " $(addsuffix .c, $(basename $(notdir $@)))
	@$(CC) $(CFLAGS) -c $< -o $@

$(obj)%.o:	%.cpp
	@echo "Compling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	@$(CXX) $(CFLAGS) -c $< -o $@
