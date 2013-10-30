###
# filename: learn_c.makefile
# make -f learn_c.makefile all
# make -f learn_c.makefile clean
###
CC = gcc
CFLAGS = -g -Wall
LIBSO = -shared -fPIC
LIBSOLIST = -lmylib -ltimer -lgetopt_long -lshow_bytes
INCLUDESDIR =
LIBSDIR = lib
LBIN = bin
LOBJ = obj
LDOC = doc
LSRC = src
DESTDIR =
PREFIX = $(DESTDIR)/usr/local
LIBSOFILES = $(LIBSDIR)/libmylib.so $(LIBSDIR)/libtimer.so $(LIBSDIR)/libgetopt_long.so $(LIBSDIR)/libshow_bytes.so

all: learn_c

learn_c: $(LBIN)/learn_c
$(LBIN)/learn_c: $(LBIN)/learn_c.o $(LIBSOFILES)
	@printf "building1...learn_c\n"
	$(CC) $(CFLAGS) $< -L$(LIBSDIR) $(LIBSOLIST) -o $@
	@printf "building1...learn_c!!!\n"

$(LBIN)/learn_c.o: learn_c.c learn_c.h
	@printf "building2...lib/learn_c.o\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "building2...lib/learn_c.o!!!\n"

$(LIBSDIR)/libmylib.so: learn_c_mylib.c learn_c_mylib.h
	@printf "building3...lib/libmylib.so\n"
	$(CC) $(CFLAGS) $< $(LIBSO) -o $@
	@printf "building3...lib/libmylib.so!!!\n"

$(LIBSDIR)/libtimer.so: timer.c timer.h
	@printf "building4...lib/libtimer.so\n"
	$(CC) $(CFLAGS) $< $(LIBSO) -o $@
	@printf "building4...lib/libtimer.so!!!\n"

$(LIBSDIR)/libgetopt_long.so: getopt_long.c getopt_long.h
	@printf "building5...lib/libgetopt_long.so\n"
	$(CC) $(CFLAGS) $< $(LIBSO) -o $@
	@printf "building5...lib/libgetopt_long.so!!!\n"

$(LIBSDIR)/libshow_bytes.so: show_bytes.c show_bytes.h
	@printf "building6...lib/libshow_bytes.so\n"
	$(CC) $(CFLAGS) $< $(LIBSO) -o $@
	@printf "building6...lib/libshow_bytes.so!!!\n"
clean:
	@printf "clean the (./bin/* && ./lib/*) ....\n"
	-rm -f $(LBIN)/*
	-rm -f $(LIBSDIR)/*
	@printf "clean is done!!!\n"

run_learn_c:
	LD_LIBRARY_PATH=./lib/ ./bin/learn_c

gdb:

.PHONY: all learn_c clean run_learn_c gdb
