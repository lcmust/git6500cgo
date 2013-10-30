#KERNELDIR := /usr/src/linux-headers-3.2.0-4-686-pae
obj-m := hello.o

all :
	#make -C /root/linux-2.6.28 SUBDIRS=`pwd` modules  #write of book
	#make -C /usr/src/linux-source-3.2 M=`pwd` modules  #report no symbol version for module_layout
	make -C /lib/modules/`uname -r`/build M=`pwd` modules  #worked well

clean :
	rm *.o *.ko *.mod.c *.order *.symvers
