; A simple boot sector that prints a message to the screen using a BIOS routine
;[org 0x7c00]
mov ah, 0x0e ; set scrolling teletype BIOS routine

mov al, secret ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

mov al, [secret]
int 0x10

mov bx, secret
add bx, 0x7c00
mov al, [bx]
int 0x10

mov al, [0x7c1e]
int 0x10

jmp $
; jmp $ is optional here
; Padding and magic BIOS number

; data

secret:
	db "X"

times 510-($-$$) db 0
dw 0xAA55