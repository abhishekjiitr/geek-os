all: boot.flp
	qemu-system-i386 -fda floppy.flp

boot.flp: boot.bin
	dd status=noxfer conv=notrunc if=boot.bin of=floppy.flp

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

clean:
	\rm *.bin *.flp
