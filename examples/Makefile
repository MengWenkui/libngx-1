# Makefile for Fedora platform
# Modify it, if needed

#LIBNGX_BASE_DIR=/usr/local
LIBNGX_BASE_DIR=/tmp/nginx
LIBNGX_DIR= $(LIBNGX_BASE_DIR)/lib
LIBNGX_INCS= $(LIBNGX_BASE_DIR)/include

CC= gcc
CFLAGS= -O2 -I. -I$(LIBNGX_INCS)
#SYSLIB= -L$(LIBNGX_DIR) -lngx -lpthread -lcrypt -lpcre -lcrypto -lz
SYSLIB= -L$(LIBNGX_DIR) -lngx -lpthread
STRIP= strip

C_FILES= \
	stringtest.c \
	pooltest.c

O_FILES= $(C_FILES:.c=.o)

default:
	@echo "                                                       "
	@echo "  Usage:                                               "
	@echo "                                                       "
	@echo "    make all [LIBNGX_BASE_DIR='/base/path/to/libngx']  "
	@echo "                                                       "
	@echo "    make test                                          "
	@echo "                                                       "


TESTS= \
	stringtest \
	pooltest


all: $(TESTS)

test: all
	for t in $(TESTS); do echo "**** Runing $$t"; ./$$t || exit 1; done

stringtest: stringtest.o
	$(CC) -o $@ $< $(SYSLIB)
	$(STRIP) $@

pooltest: pooltest.o
	$(CC) -o $@ $< $(SYSLIB)
	$(STRIP) $@

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $< 

.PHONY: clean test

clean:
	rm -f $(TESTS) *.o *~

