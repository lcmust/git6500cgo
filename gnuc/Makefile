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
LBIN = bin
LOBJ = obj
LDOC = doc
LSRC = src
DESTDIR =
PREFIX = $(DESTDIR)/usr/local

all: learn_c fib_1
learn_c: $(LIBSDIR)/learn_c.o $(LIBSDIR)/liblearn_c_mylib.so $(LIBSDIR)/libtimer.so
	@printf "building 1\n"
	@printf "building...learn_c\n"
	$(CC) $(CFLAGS) $(LIBS) -L$(LIBSDIR) $< -o $(LBIN)/$@
	@printf "building...learn_c!!!\n"
# gcc -g -Wall -L ./lib/ -llearn_c_mylib $< -o ./lib/learn_c.o

$(LIBSDIR)/learn_c.o: learn_c.c learn_c.h
	@printf "building 2\n"
	@printf "building...lib/learn_c.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building...lib/learn_c.o!!!\n"
# gcc -g -Wall -c learn_c.c -o ./lib/learn_c.o

$(LIBSDIR)/liblearn_c_mylib.so: learn_c_mylib.c
	@printf "building 3\n"
	@printf "building...lib/liblearn_c_mylib.so\n"
	$(CC) $(CFLAGS) $(LIBSO) $< -o $@
	@printf "building...lib/liblearn_c_mylib.soo!!!\n"
# gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/liblearn_c_mylib.so

$(LIBSDIR)/libtimer.so: timer.c timer.h
	@printf "building 4\n"
	@printf "building...lib/libtimer.so\n"
	$(CC) $(CFLAGS) $(LIBSO) $< -o $@
# gcc -g -Wall -shared -fPIC timer.c -o lib/libtimer.so

fib_1: $(LIBSDIR)/fib_1.o
	@printf "building fib_1\n"
#	$(CC) $(CFLAGS) $< -o $(LBIN)/$@
	$(CC) $(CFLAGS) $< -o $(LBIN)/$@
	@printf "building fib_1!!!\n"

$(LIBSDIR)/fib_1.o: fib_1.c
	@printf "building fib_1.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building fib_1.o!!!\n"

clean:
	@printf "clean the ./lib/*.* ....\n"
	rm -f $(LIBSDIR)/*
	@printf "clean is done!!!\n"

.PHONY: all clean

