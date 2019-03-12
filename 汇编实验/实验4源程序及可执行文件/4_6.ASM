PUBLIC CRLF
PUBLIC BUF
PUBLIC X
PUBLIC IN_NAME
EXTERN SHOWALL:NEAR
EXTERN SORT:NEAR
.386
STACK SEGMENT STACK USE16 PARA STACK 'STACK'
      DB      200 DUP(0)
STACK ENDS
DATAS SEGMENT USE16 PARA PUBLIC 'DATAS'
NUM    DB  1,?,1 DUP(0)
N      EQU 5
K      EQU 0
X      EQU 16
BUF    DB 10 DUP(0)   ;学生姓名，不足10个字节的部分用0填充
       DB 100,85,80,40   ; 平均成绩还未计算
       DW 0
       DB 10 DUP(0)
       DB 80,100,70,20
       DW 0
       DB N-3 DUP(10 DUP(0),80,90,95,30,0,0) ;除了3个已经具体定义了学生信息的成绩表以外，其他学生的信息暂时假定为一样的。
       DB 10 DUP(0)     ;最后一个必须是自己名字的拼音
       DB 85,85,100,70
       DW 0
POIN   DW 0
CRLF   DB 0AH,0DH,'$';回车换行
CHAR   DB 0
SCORE  DB 3,?,3 DUP(0)
in_name DB 20,?,20 DUP(0)
MSG1 DB 'Please choose the number you want.$'
MSG2 DB 0AH,0DH,'1=input,2=calculate the ave,3=rank,4=output,5=quit$'
STR1 DB 'Please input student name:$'
STR2 DB 'Unexpected character or too long string detected!$'
STR3 DB 'A variate has not been initialized!$'
STR4 DB 'Can not find match name!$'
STR5 DB 'The average score is $$$$'
STR6 DB 'Overflow score detected!$'
STR7 DB 'Score validation succeed.$'
STR8 DB 'You are inputing no.1 student.$'
STR9 DB 'Please input scores.$'
STR10 DB 'You are inputing no.2 student.$'
STR11 DB 'You are inputing no.3 student.$'
STR12 DB 'You are inputing no.4 student.$'
STR13 DB 'You are inputing no.5 student.$'
STR14 DB "Score:               Average score:$$$$"
		
		Temp DB "   "
		Temp1 DB "   "

DATAS ENDS
CODES  SEGMENT USE16 PARA PUBLIC 'CODE'
ASSUME CS:CODES,DS:DATAS,SS:STACK
BEGIN:	MOV AX,DATAS
        MOV DS,AX
        MOV ES,AX
WRT     MACRO A
        LEA DX,A
        MOV AH,9
        INT 21H
        ENDM
READ    MACRO A
        LEA DX,IN_NAME
        MOV AH,10
        INT 21H
        ADD DX,2
        MOV SI,DX
        LEA DI,A
        MOV CX,9
        CLD
	REP MOVSB
        ENDM
READ1   MACRO A
        LEA DX,A
        MOV AH,10
        INT 21H
        ENDM
SAT:    WRT MSG1
        WRT MSG2
        WRT CRLF
        MOV AH,1
        INT 21H
        CMP AL,'5'
        JGE QUIT
        CMP AL,'4'
        JE  SHOW
        CMP AL,'3'
        JE  SOT
        CMP AL,'2'
        JE  AVE
        CMP AL,'1'
        JE  LI
AVE:    CALL AVERAGE
        JMP SAT
LI:     CALL INPUT
        JMP SAT
SHOW:   MOV BX,OFFSET BUF
        PUSH BX
        MOV BX,5
        PUSH BX
        CALL SHOWALL
        JMP SAT
SOT:    MOV BX,OFFSET BUF
        PUSH BX
        MOV BX,5
        PUSH BX
        CALL SORT
        JMP SAT
INPUT   PROC NEAR
        PUSH DI
        PUSH AX
        PUSH CX
        PUSH BX
        MOV CX,5
        MOV BX,OFFSET BUF
INPUT1: PUSH CX
        WRT CRLF
        CMP CX,5
        JE  S8
        CMP CX,4
        JE  S10
        CMP CX,3
        JE  S11
        CMP CX,2
        JE  S12
        CMP CX,1
        JE  S13
S8:     WRT STR8
        WRT CRLF
        WRT STR1
        READ BUF
        JMP LPP
S10:    WRT STR10
        WRT CRLF
        WRT STR1
        READ BUF+16
        JMP LPP
S11:    WRT STR11
	WRT CRLF
        WRT STR1
        READ BUF+32
        JMP LPP
S12:    WRT STR12
	WRT CRLF
        WRT STR1
        READ BUF+48
        JMP LPP
S13:    WRT STR13
	WRT CRLF
        WRT STR1
        READ BUF+64
        JMP LPP
LPP:    WRT CRLF
        WRT STR9
        READ1 SCORE
	MOV CX,0
	MOV CH,SCORE+3
        CMP CH,0DH
        JE  LPP1
        MOV CL,SCORE+2
        SUB CL,30H
        MOV CH,0
        IMUL CX,10
        MOV CH,SCORE+3
        SUB CH,30H
        ADD CL,CH
        MOV CH,0
        MOV [BX+10],CX
	JMP LPPP1
LPP1:   MOV CL,SCORE+2
        SUB CL,30H
        MOV CH,0
        MOV [BX+10],CX
LPPP1:  WRT CRLF
        WRT STR9
        READ1 SCORE
        MOV CX,0
	MOV CH,SCORE+3
        CMP CH,0DH
        JE  LPP2
        MOV CL,SCORE+2
        SUB CL,30H
        MOV CH,0
        IMUL CX,10
        MOV CH,SCORE+3
        SUB CH,30H
        ADD CL,CH
        MOV CH,0
        MOV [BX+11],CX
	JMP LPPP2
LPP2:   MOV CL,SCORE+2
        SUB CL,30H
        MOV CH,0
        MOV [BX+11],CX
LPPP2:  WRT CRLF
        WRT STR9
        READ1 SCORE
        MOV CX,0
	MOV CH,SCORE+3
        CMP CH,0DH
        JE  LPP3
        MOV CL,SCORE+2
        SUB CL,30H
        MOV CH,0
        IMUL CX,10
        MOV CH,SCORE+3
        SUB CH,30H
        ADD CL,CH
        MOV CH,0
        MOV [BX+12],CX
	JMP LPPP3
LPP3:   MOV CL,SCORE+2
	SUB CL,30H
        MOV CH,0
        MOV [BX+12],CX
LPPP3:  ADD BX,X
        POP CX       
        DEC CX
        JNZ INPUT1
        POP BX 
        POP CX
        POP AX 
        POP DI
        RET
INPUT   ENDP  
AVERAGE PROC NEAR
        PUSH BX
        PUSH AX
        PUSH SI
        PUSH DX
        PUSH CX
        MOV SI,0
        MOV CL,3
        MOV BX,OFFSET BUF
LP:     MOV AX,0
        MOV DX,0
        MOV AL,[BX+SI+10]
        MOV DL,[BX+SI+11]
        ADD AX,DX
        MOV DL,[BX+SI+12] 
        ADD AX,DX
        DIV CL
        MOV AH,0
        MOV [BX+SI+13],AL
        ADD SI,16
        CMP SI,80
        JNE LP
        POP CX
        POP DX 
        POP SI
        POP AX
        POP BX
        RET
AVERAGE ENDP                
QUIT:   MOV AH,4CH   ;EXIT
        INT 21H 
CODES	ENDS
	END BEGIN
