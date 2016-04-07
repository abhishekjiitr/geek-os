; A simple boot sector that prints a message to the screen using a BIOS routine
[org 0x7c00]
;mov ah, 0x0e ; set scrolling teletype BIOS routine

%include "print_string.asm"
; %include "print_hex.asm"

mov ah, 0x02
mov dl, 0
mov ch, 3
mov dh, 1

mov cl, 4
mov al, 5

mov bx, 0xa000
mov es, bx
mov bx, 0x1234

int 0x13 

jc disk_error
cmp al, 5
jne disk_error

jmp fix3
disk_error:
	mov bx, DISK_ERROR_MSG
	call print_string
fix3:

jmp $


; data

DISK_ERROR_MSG:
	db 'Disk read error!', 0 ; NULL terminated string declaration

times 510-($-$$) db 0
dw 0xAA55