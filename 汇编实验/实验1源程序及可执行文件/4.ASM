;----------------------------
.386
STACK	SEGMENT STACK USE16
	DB	200 DUP(0)
STACK	ENDS
;----------------------------
DATA	SEGMENT USE16
MSG1    DB  'Hello 123'
LEN     =  $-MSG1
MSG2    DB  LEN  DUP(0)
DATA	ENDS
;------------------------------
CODE SEGMENT  USE16
        ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:	MOV AX,DATA
        MOV DS,AX
        MOV SI,0
        MOV BP,LEN
LP:     MOV AL,MSG1[SI]
        MOV MSG2[BP],AL
        DEC BP
        INC SI
        CMP SI,LEN
        JNE LP
        MOV AH,4CH   ;EXIT
        INT 21H
;-----------------------------
CODE	ENDS
	END BEGIN
