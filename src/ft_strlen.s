global ft_strlen
extern hello_world

section .text
ft_strlen:
	mov rdi, rbx		; take input string
	call hello_world
	mov rax, 0			; output
	ret
