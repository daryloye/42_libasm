global ft_strcpy

section .text
ft_strcpy:
	mov rax, rdi		; return ptr to dest

.loop:
	mov al, [rsi]		; move src[i] to al register
	mov [rdi], al		; move al to dest[i]
	inc rsi
	inc rdi
	test al, al			; if al is null (0), 0 && 0 = 0
	jnz .loop			; repeat loop if not \0

.done:
	ret

; char *ft_strcpy(char *dest, const char *src)
; {
;	size_t	i = 0;
;	while (src[i])
;	{
;		dst[i] = src[i];
;		i++;
;	}
;	dest[i] = '\0';
;	return (dest);
; }