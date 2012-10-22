# Makefile for Fadora platform
# Modify it, if needed

#LIBNGX_BASE_DIR=/usr/local
LIBNGX_BASE_DIR=/tmp/test
LIBNGX_DIR= $(LIBNGX_BASE_DIR)/lib
LIBNGX_INCS= $(LIBNGX_BASE_DIR)/include

CC= gcc
CFLAGS= -O2 -I. -I$(LIBNGX_INCS)
#SYSLIB= -L$(LIBNGX_DIR) -lngx -lpthread -lcrypt -lpcre -lcrypto -lz
SYSLIB= -L$(LIBNGX_DIR) -lngx
STRIP= strip

C_FILES= \
	test.c

O_FILES= $(C_FILES:.c=.o)

default:
	@echo "  Usage:                                             "
	@echo "                                                     "
	@echo "    make all [LIBNGX_BASE_DIR=base path to libngx']  "
	@echo "    make all                                         "
	@echo "                                                     "

all: test

test: $(O_FILES)
	$(CC) -o $@ $< $(SYSLIB)
	$(STRIP) $@

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $< 

.PHONY: clean

clean:
	rm -f test *.o *~


