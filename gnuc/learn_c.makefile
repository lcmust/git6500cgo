###
# learn_c/: Makefile
# make all
# make lean
###
CC = gcc
CFLAGS = -g -Wall
LIBSO = -shared -fPIC
LIBS = -lmylib -ltimer
INCLUDESDIR =
LIBSDIR = lib
LBIN = bin
LOBJ = obj
LDOC = doc
LSRC = src
DESTDIR =
PREFIX = $(DESTDIR)/usr/local

all: learn_c fib_1
learn_c: $(LBIN)/learn_c $(LBIN)/fib_1
$(LBIN)/learn_c: $(LIBSDIR)/learn_c.o $(LIBSDIR)/libmylib.so $(LIBSDIR)/libtimer.so
	@printf "building 1\n"
	@printf "building...learn_c\n"
	$(CC) $(CFLAGS) $(LIBS) -L$(LIBSDIR) $< -o $@
	@printf "building...learn_c!!!\n"
	# gcc -g -Wall -L ./lib/ -lmylib -ltimer $< -o ./bin/learn_c

$(LIBSDIR)/learn_c.o: learn_c.c learn_c.h
	@printf "building 2\n"
	@printf "building...lib/learn_c.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building...lib/learn_c.o!!!\n"
	# gcc -g -Wall -c learn_c.c -o ./lib/learn_c.o

$(LIBSDIR)/libmylib.so: learn_c_mylib.c
	@printf "building 3\n"
	@printf "building...lib/libmylib.so\n"
	$(CC) $(CFLAGS) $(LIBSO) $< -o $@
	@printf "building...lib/libmylib.so!!!\n"
	# gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/libmylib.so

$(LIBSDIR)/libtimer.so: timer.c timer.h
	@printf "building 4\n"
	@printf "building...lib/libtimer.so\n"
	$(CC) $(CFLAGS) $(LIBSO) $< -o $@
	# gcc -g -Wall -shared -fPIC timer.c -o lib/libtimer.so

fib_1: $(LBIN)/fib_1
$(LBIN)/fib_1: $(LIBSDIR)/fib_1.o
	@printf "building fib_1\n"
	$(CC) $(CFLAGS) $< -o $@
	@printf "building fib_1!!!\n"
	# gcc -g -Wall ./lib/fib_1.o -o ./bin/fib_1
	
$(LIBSDIR)/fib_1.o: fib_1.c
	@printf "building fib_1.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building fib_1.o!!!\n"

clean:
	@printf "clean the ./lib/*.* ....\n"
	rm -f $(LIBSDIR)/*
	@printf "clean is done!!!\n"

run_learn_c:
	LD_LIBRARY_PATH=./lib ./bin/learn_c

run_fib_1:
	LD_LIBRARY_PATH=./lib ./bin/fib_1

gdb:

.PHONY: all learn_c fib_1 clean run_learn_c run_fib_1 gdb

