###
# filename: learn_c.makefile
# make -f learn_c.makefile all
# make -f learn_c.makefile clean
###
CC = gcc
CFLAGS = -g -Wall
LIBSO = -shared -fPIC
LIBS = -lmylib -ltimer -lgetopt_long
INCLUDESDIR =
LIBSDIR = lib
LBIN = bin
LOBJ = obj
LDOC = doc
LSRC = src
DESTDIR =
PREFIX = $(DESTDIR)/usr/local

all: learn_c fib_1

learn_c: $(LBIN)/learn_c
$(LBIN)/learn_c: $(LBIN)/learn_c.o $(LBIN)/mylib.o $(LBIN)/timer.o $(LBIN)/getopt_long.o
	@printf "building 1\n"
	@printf "building...learn_c\n"
	$(CC) $(CFLAGS) $^ -o $@
	@printf "building...learn_c!!!\n"

$(LBIN)/learn_c.o: learn_c.c learn_c.h
	@printf "building 2\n"
	@printf "building...lib/learn_c.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building...lib/learn_c.o!!!\n"

$(LBIN)/mylib.o: learn_c_mylib.c
	@printf "building 3\n"
	@printf "building...lib/libmylib.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building...lib/libmylib.o!!!\n"

$(LBIN)/timer.o: timer.c timer.h
	@printf "building 4\n"
	@printf "building...lib/libtimer.o\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(LBIN)/getopt_long.o: getopt_long.c getopt_long.h
	@printf "building 4\n"
	@printf "building...lib/libgetopt_long.o\n"
	$(CC) $(CFLAGS) -c $< -o $@

fib_1: $(LBIN)/fib_1
$(LBIN)/fib_1: $(LBIN)/fib_1.o
	@printf "building fib_1\n"
	$(CC) $(CFLAGS) $< -o $@
	@printf "building fib_1!!!\n"

$(LBIN)/fib_1.o: fib_1.c
	@printf "building fib_1.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building fib_1.o!!!\n"

clean:
	@printf "clean the (./bin/*) ....\n"
	-rm -f $(LBIN)/*
	@printf "clean is done!!!\n"

run_learn_c:
	./bin/learn_c

run_fib_1:
	./bin/fib_1

gdb:

.PHONY: all learn_c fib_1 clean run_learn_c run_fib_1 gdb
