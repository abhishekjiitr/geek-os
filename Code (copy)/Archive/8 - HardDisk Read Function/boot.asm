; A simple boot sector that prints a message to the screen using a BIOS routine
[org 0x7c00]
;mov ah, 0x0e ; set scrolling teletype BIOS routine

%include "print_string.asm"
%include "print_hex.asm"
%include "disk_load.asm"
mov [BOOT_DRIVE], dl

mov bp, 0x8000
mov sp, bp

mov bx, 0x9000
mov dh, 5
mov dl, [BOOT_DRIVE]
call disk_load

mov dx, [0x9000]
call print_hex

mov dx, [0x9000+512]
call print_hex


jmp $


; data

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xAA55

; Hard disk part now
times 256 dw 0xdada
times 256 dw 0xface