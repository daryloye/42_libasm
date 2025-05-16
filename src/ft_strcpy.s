global ft_strcpy

section .text
ft_strcpy:
	mov rax, rdi		; return dest ptr

.loop:
	mov al, [rsi]		; store the value of rsi in al register
	mov [rdi], al		; set the value of rdi to al
	inc rsi
	inc rdi
	test al, al			; check if al is 0 ('test' must involve >1 register)
	jnz .loop			; repeat loop if not '\0'

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