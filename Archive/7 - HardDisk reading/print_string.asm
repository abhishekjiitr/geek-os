jmp fix ; fixes a goddamn bloody error that only god knows solution to ;(
print_string:
	pusha
	mov si, bx

	print:
		mov ah, 0x0e ; set scrolling teletype BIOS routine
		mov al, [si] ; set al reg. to character to print
		inc si
		or al, al
		jz end
		int 0x10 ; give interrupt to print on screen
		jmp print
	end:
		popa
		ret
fix: