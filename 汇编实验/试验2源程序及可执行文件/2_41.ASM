;----------------------------
.386
STACK	SEGMENT STACK USE16
	DB	200 DUP(0)
STACK	ENDS
;----------------------------
DATA	SEGMENT USE16
N       EQU  5
BUF1	DB   'zhangsan',0,0
        DB   100,85,90,?
        DB   'lisi',6 DUP(0)
        DB   80,90,90,?
        DB   N-3 DUP('TempValue',0,80,90,95,?)
        DB   'linxiaob',0,0
        DB   85,95,100,?
in_name DB   10,11 DUP(0)
POIN    DW   10,11 dup(0)
BUF3    DB   0AH,0DH,'can not find the student$'
BUF2    DB   0AH,0DH,'Please enter your name:$'
DATA	ENDS
;------------------------------
CODE SEGMENT USE16
        ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:	MOV AX,DATA
        MOV DS,AX
        LEA DX,BUF2
        MOV AH,9
        INT 21H
        LEA DX,IN_NAME
        MOV AH,10
        INT 21H  ;任务一
        MOV SI,OFFSET BUF1
        MOV DI,OFFSET IN_NAME
        INC DI
        INC DI
        MOV DX,N
LP2:    MOV CL,0
LP:     MOV AL,[SI]
        MOV BL,[DI]
        CMP AL,BL
        JNE LP1
        INC SI
        INC DI
        INC CL
        CMP CL,IN_NAME+1
        JNE LP
        CMP BYTE PTR [SI],0
        JNE LP
        MOV CH,0
        SUB SI,CX
        MOV POIN,SI
        JMP AVE
LP1:    MOV CH,0
        MOV BX,14
        SUB BX,CX
        ADD SI,BX
        MOV DI,OFFSET IN_NAME
        INC DI
        INC DI
        DEC DX
        JNZ LP2
        LEA DX,BUF3
        MOV AH,9H
        INT 21H
        MOV AH,4CH   ;EXIT
        INT 21H;任务二
AVE:    MOV SI,OFFSET BUF1
	MOV DI,N
LP3:    MOV AL,[SI+10]
	MOV BL,[SI+11]
	MOV CL,[SI+12]
	MOV AH,0
	MOV BH,0
	MOV CH,0
	SAL AX,2
	SAL BX,1
	ADD AX,BX
	ADD AX,CX
	MOV CL,7
	DIV CL
	MOV [SI+13],AL
	ADD SI,14
	DEC DI
	JNZ LP3	;renwu3 
        MOV DL,0AH
        MOV AH,2H
        INT 21H     
        MOV BX,POIN;ERROR
        MOV AX,DS:[BX+13]
        CMP AL,90        
        JGE LEVEL1
        CMP AL,80
        JGE LEVEL2
        CMP AL,70
        JGE LEVEL3
        CMP AL,60
        JGE LEVEL4
LEVEL1: MOV DL,'A'         
	MOV AH,2H
        INT 21H 
        MOV AH,4CH   ;EXIT
        INT 21H
LEVEL2: MOV DL,'B'         
	MOV AH,2H
        INT 21H
        MOV AH,4CH   ;EXIT
        INT 21H
LEVEL3: MOV DL,'C'         
	MOV AH,2H
        INT 21H 
        MOV AH,4CH   ;EXIT
        INT 21H
LEVEL4: MOV DL,'D'         
	MOV AH,2H
        INT 21H
        MOV AH,4CH   ;EXIT
        INT 21H
 ;-----------------------------
CODE	ENDS
	END BEGIN
