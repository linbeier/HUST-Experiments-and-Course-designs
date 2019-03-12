;----------------------------
.386
STACK	SEGMENT USE16 STACK
	DB	200 DUP(0)
STACK	ENDS
;----------------------------
DATA	SEGMENT USE16
BUF1    DB 0,1,2,3,4,5,6,7,8,9
BUF2    DB 10 DUP(0)
BUF3    DB 10 DUP(0)
BUF4    DB 10 DUP(0)
DATA	ENDS
;------------------------------
CODE SEGMENT  USE16
        ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:	MOV AX,DATA
        MOV DS,AX
        MOV ESI,0
        MOV CX,0
   
LOPA:   MOV AL,BUF1[ESI]
        MOV BUF2[ESI],AL
        INC AL
        MOV BUF3[ESI],AL
        ADD AL,3
        MOV BUF4[ESI],AL
        INC ESI
        INC CX
        CMP CX,10
        JNE LOPA
        MOV AH,4CH   ;EXIT
        INT 21H
;-----------------------------
CODE	ENDS
	END BEGIN
