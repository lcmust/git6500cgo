###
# learn_c/: Makefile
# make all
# make lean
###
CC = gcc
CFLAGS = -g -Wall
LIBSO = -shared -fPIC
LIBS = -llearn_c_mylib -ltimer
INCLUDESDIR =
LIBSDIR = lib
DESTDIR =
SOURDIR =  /mnt/sda6e/Bk2010-cl/cl-xx-2010cl/Lin/LinuxC/cxx/unpv12e_cl

all: test

run: test
	./test

rootrun: test
	sudo ./test

test: raw_sockets.c
	$(CC) $(CFLAGS) $< -o $@

raw_sockets.c: $(SOURDIR)/raw_sockets.c
	cp $< $@

csum123.c: $(SOURDIR)/csum123.c
	cp $< $@

clean:
	rm -f test

.PHONY: run rootrun all clean
