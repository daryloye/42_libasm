global ft_strcmp

section .text
ft_strcmp:

.loop:
	cmp byte [rdi], 0	; check if rdi is '\0'
	je .done

	cmp byte [rsi], 0	; check if rsi is '\0'
	je .done
	
	mov al, [rdi]
	cmp al, [rsi]		; check if rdi == rsi
	jne .done

	inc rdi
	inc rsi
	jmp .loop

.done:
	movzx rax, byte [rdi]	; move byte (8-bit) to rax (64-bit). movzx sets the remaining 24 bits to 0
	movzx rbx, byte [rsi]
	sub rax, rbx
	ret 


; int	ft_strcmp(const char *s1, const char *s2)
; {
;	size_t	i;
;	i = 0;
;	while (s1[i] && s2[i])
;	{
;		if (s1[i] == s2[i])
;			i++;
;		else
;			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
;	}
;	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
; }