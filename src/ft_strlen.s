global ft_strlen

section .text
ft_strlen:
	xor rax, rax				; set return value (len) in rax to 0 (more optimised than mov rax, 0)

.loop:
	cmp byte [rdi + rax], 0		; check if s[len] == '/0'
	je .done
	inc rax
	jmp .loop

.done:
	ret


; size_t	ft_strlen(const char *s)
; {
;	size_t	i = 0;
;	while (s[i])
;		i++;
;	return (i);
; }
