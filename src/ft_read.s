global ft_read
section .text
ft_read:
	mov rax, 0
	syscall
	test rax, rax
	js .error
	ret

.error:
	neg rax								; get absolute value of the error
	mov rdi, rax						; temp store because the errno_location call will override rax
	call __errno_location wrt ..plt		; route the call through PLT (Procedure Linkage Table)
	mov [rax], rdi						; move the error code to the errno_location
	mov rax, -1
	ret