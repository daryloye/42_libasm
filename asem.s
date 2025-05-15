section .bss

section .text
	global _start
	
	_start:
		mov rax, 1
		mov rdi, 1
		lea rsi, [rel str]
		mov rdx, strLen
		syscall

		mov rax, 60
		mov rdi, 69
		syscall

section .data
	align 2
	str: db 'Hello, World!', 0xA, 0
	strLen: equ $-str