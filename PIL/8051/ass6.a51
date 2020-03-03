ORG 0000H
ljmp start

START:
	MOV R0,#40H
	MOV R3,10H
	CLR A

SUM:
	ADD A,@R0
	INC R0
	DJNZ R3,SUM
	mov r6, a
	mov r7, a

NEXT:
	SJMP NEXT

END





