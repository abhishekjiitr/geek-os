; A simple boot sector that prints a message to the screen using a BIOS routine

mov ah, 0x0e ; set scrolling teletype BIOS routine

mov al, 'H' ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

mov al, 'e' ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

mov al, 'l' ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

mov al, 'l' ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

mov al, 'o' ; set al reg. to character to print
int 0x10 ; give interrupt to print on screen

; jmp $ is optional here
; Padding and magic BIOS number

times 510-($-$$) db 0
dw 0xAA55