###
# filename: learn_c.makefile
# make -f learn_c.makefile all
# make -f learn_c.makefile clean
###
CC = gcc
CFLAGS = -g -Wall
LIBSO = -shared -fPIC
LIBS = -lmylib -ltimer -lgetopt_long -lshow_bytes
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
$(LBIN)/learn_c: $(LBIN)/learn_c.o $(LBIN)/mylib.o $(LBIN)/timer.o $(LBIN)/getopt_long.o $(LBIN)/show_bytes.o
	@printf "building 1\n"
	@printf "building...learn_c\n"
	$(CC) $(CFLAGS) $^ -o $@
	@printf "building...learn_c!!!\n"

$(LBIN)/learn_c.o: learn_c.c learn_c.h
	@printf "building2...bin/learn_c.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building2...bin/learn_c.o!!!\n"

$(LBIN)/mylib.o: learn_c_mylib.c learn_c_mylib.h
	@printf "building3...bin/mylib.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building3...bin/mylib.o!!!\n"

$(LBIN)/timer.o: timer.c timer.h
	@printf "building4...bin/timer.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building4...bin/timer.o!!!\n"

$(LBIN)/getopt_long.o: getopt_long.c getopt_long.h
	@printf "building5...bin/getopt_long.o\n"
	@printf "building5...bin/getopt_long.o!!!\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(LBIN)/show_bytes.o: show_bytes.c show_bytes.h
	@printf "building6...bin/show_bytes.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building6...bin/show_bytes.o!!!\n"

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
