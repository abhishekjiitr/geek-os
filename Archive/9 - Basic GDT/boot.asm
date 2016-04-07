; A simple boot sector that prints a message to the screen using a BIOS routine
[org 0x7c00]
;mov ah, 0x0e ; set scrolling teletype BIOS routine


jmp $


; data

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xAA55

; Hard disk part now
times 256 dw 0xdada
times 256 dw 0xface