#This is makefile that automates everything.

all: os-image
	qemu-system-i386 os-image 
	make clean

os-image: boot_sect.bin kernel.bin
	cat boot_sect.bin kernel.bin > os-image
	
kernel.bin: kernel/kernel.c kernel/entry.asm
	nasm kernel/entry.asm -f elf64 -o entry.o
	gcc -ffreestanding -c kernel/kernel.c -o kernel.o
	ld -o kernel.bin -Ttext 0x1000 entry.o kernel.o --oformat binary

boot_sect.bin: boot/boot.asm
	nasm boot/boot.asm -o boot_sect.bin

clean:
	rm *.bin *.o os-image
