;----------------------------
.386
STACK	SEGMENT STACK USE16
	DB	200 DUP(0)
STACK	ENDS
;----------------------------
DATA	SEGMENT USE16
XUEHAO	DB      4 DUP(0)
DATA	ENDS
;------------------------------
CODE SEGMENT USE16
        ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:	MOV AX,DATA
        MOV DS,AX
        MOV BX,OFFSET XUEHAO
        MOV AL,'4'
        MOV [BX],AL  ;寄存器间接寻址
        MOV AL,'8'
        MOV [BX]+1,AL  ;变址寻址
        MOV SI,2
        MOV AL,'3'
        MOV [BX][SI],AL ;基址加变址寻址
        MOV AL,'6'
        MOV DS:[3H],AL ;直接寻址
        MOV AH,4CH   ;EXIT
        INT 21H
;-----------------------------
CODE	ENDS
	END BEGIN
