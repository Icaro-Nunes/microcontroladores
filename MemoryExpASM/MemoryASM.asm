inicio:
	palavra: ds 8
	
	mov palavra,#50h ;P
	mov palavra+1,#72h ;r
	mov palavra+2,#6fh ;o
	mov palavra+3,#67h ;g
	mov palavra+4,#72h ;r
	mov palavra+5,#61h ;a
	mov palavra+6,#6dh ;m
	mov palavra+7,#61h ;a

	POSICAO_P IDATA palavra
	POSICAO_as IDATA palavra+7

loop:
	mov A, #POSICAO_P
	cpl A
	mov P1, A

	mov A, @POSICAO_P
	cpl A
	mov P2, A

	mov A, #POSICAO_as
	cpl A
	mov P3, A

	mov A, @POSICAO_as
	cpl A
	mov P0, A

	jmp loop

end