global hello_world

section .text
hello_world:
	mov rax, 1
	mov rdi, 1
	lea rsi, [rel str]
	mov rdx, strLen
	syscall

section .data
	align 2
	str: db 'Hello, World!', 0xA, 0
	strLen: equ $-str