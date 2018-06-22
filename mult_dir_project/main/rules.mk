#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
#
# A simple way to generate depend file(.depend) for .c & .cpp,
# so you change the head file, it will recompile the 
# file(s) which include the head file.
#

_depend: $(obj).depend

$(obj).depend: $(TOPDIR)/config.mk $(SRC_C) $(SRC_CPP)
	@rm -f $@
	@for f in $(SRC_C); do \
		g=`basename $$f | sed -e 's/\(.*\)\.\w/\1.o/'`; \
		$(CC) $(CFLAGS) -E -MQ $(_obj)$$g $$f >> $@ ; \
	done
	@for f in $(SRC_CPP); do \
		g=`basename $$f | sed -e 's/\(.*\)\...\w/\1.o/'`; \
		$(CC) $(CFLAGS) -E -MQ $(_obj)$$g $$f >> $@ ; \
	done
