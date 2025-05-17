global ft_write
extern __errno_location

section .text
ft_write:
	mov rax, 1		; sys_write
	syscall			; rdi = fd, rsi = buf, rdx = nbytes. will override rax with return value
	test rax, rax 	; check if rax is 0
	js .error		; handle error if <0
	ret

.error:
	neg rax								; get absolute value of the error
	mov rdi, rax						; temp store because the errno_location call will override rax
	call __errno_location wrt ..plt		; route the call through PLT (Procedure Linkage Table)
	mov [rax], rdi						; move the error code to the errno_location
	mov rax, -1
	ret