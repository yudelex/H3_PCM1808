obj-m := pcm1808.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	sudo cp pcm1808.ko /lib/modules/$(shell uname -r)
	sudo depmod -a
