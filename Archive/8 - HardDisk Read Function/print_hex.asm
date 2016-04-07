jmp fix2
print_hex:
	pusha
	mov si, HEX_OUT+2
next_character:
	mov bx, dx
	and bx, 0xf000
	shr bx, 4
	add bh, 0x30
	cmp bh, 0x39
	jg add_7

add_character_hex:
	mov al, bh
	mov [si], bh
	inc si
	shl dx, 4
	or dx, dx
	jnz next_character
	mov bx, HEX_OUT
	call print_string
	popa 
	ret
add_7:
	add bh, 0x7
	jmp add_character_hex
HEX_OUT:
	db '0x0000', 0
fix2: