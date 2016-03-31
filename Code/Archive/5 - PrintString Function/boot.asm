; A simple boot sector that prints a message to the screen using a BIOS routine
[org 0x7c00]
mov ah, 0x0e ; set scrolling teletype BIOS routine

mov bx, HELLO_MSG
call print_string

%include "print_string.asm"

jmp $


; data

HELLO_MSG:
	db 'Hello, World!', 0 ; NULL terminated string declaration

times 510-($-$$) db 0
dw 0xAA55