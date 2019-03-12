	NAME FUNC
	PUBLIC ShowALL,SORT

	.386
	DATAS SEGMENT USE16 PARA PUBLIC 'D1'
		N EQU 5
		
		BUF DB 10 DUP(0)   ;学生姓名，不足10个字节的部分用0填充
		DB 100,85,80,89   ; 平均成绩还未计算
		DW 0
		
		DB 10 DUP(0)
		DB 80,100,70,92
		DW 0
		
		DB N-3 DUP(10 DUP(0),80,90,95,73,0,0) ;除了3个已经具体定义了学生信息的成绩表以外，其他学生的信息暂时假定为一样的。
		
		DB 10 DUP(0)     ;最后一个必须是自己名字的拼音
		DB 85,85,100,84
		DW 0
		
		BUFFER DB 16 DUP(0)
		
		POIN DW 0
		CRLF DB 0AH,0DH,"$";回车换行
		CHAR DB 0
		in_name DB 20,?,20 DUP(0)
		STR1 DB "Please input student name:$"
		STR2 DB "Unexpected character or too long string detected!$"
		STR3 DB "A variate hasn't been initialized!$"
		STR4 DB "Can't find match name!$"
		STR5 DB "The average score is $$$$"
		STR6 DB "Overflow score detected!$"
		STR7 DB "Score validation succeed.$"
		STR8 DB "Name:$$$$$$$$$$"
		STR9 DB "Score:               Average score:$$$$"
		STR10 DB "Score:               Average score:$$$$"
		
		Temp DB "   "
		Temp1 DB "   "
	DATAS ENDS

	STACKS SEGMENT STACK PARA USE16
		DB 100 DUP(0)
	STACKS ENDS

	CODES SEGMENT USE16 PARA PUBLIC 'CODE'
		ASSUME CS:CODES,DS:DATAS,SS:STACKS
	START:
		MOV AX,DATAS
		MOV DS,AX
		MOV ES,AX
		
		LEA SI,BUF
		PUSH SI
		PUSH 5
		CALL ShowALL

	;要求栈中传入2个参数，首先压入的是成绩表首地址，后压入的是成绩表的人数
	SORT PROC NEAR
		;形成栈帧
		PUSH BP
		MOV BP,SP
		
		;保护环境，开辟空间
		PUSHA
		
		;SI为成绩表的首地址
		MOV SI,[BP + 6]
		MOV CX,[BP + 4]
		DEC CX
		
		MOV DX,1
		;AL用于存放临时成绩变量
		;+13后指向平均成绩
		ADD SI,13
		BubbleSort:
			CMP DX,1
			JNE SortExit
			
			XOR DX,DX
			PUSH CX
			For1:
			ADD SI,16
			PUSH SI
			MOV AL,[SI]
			LEA DI,[SI - 16]
			MOV AH,[DI]
			CMP AL,AH
			JBE For1Continue
			PUSH CX
			
			PUSH DI
			
			PUSH SI
			PUSH DI
			SUB SI,13

			LEA DI,BUFFER
			MOV CX,16
			CLD
			REP MOVSB
			POP SI
			POP DI
			
			SUB SI,13
			SUB DI,13
			MOV CX,16
			CLD
			REP MOVSB		
			
			POP DI
			SUB DI,13
			LEA SI,BUFFER
			MOV CX,16
			CLD
			REP MOVSB
			MOV DX,1
			POP CX
			
			For1Continue:
			POP SI
			DEC CX
			JNZ For1
			
			ForEnd:
			POP CX
			DEC CX
			MOV SI,[BP + 6]
			ADD SI,13
			JMP BubbleSort
			
			MOV CX,[BP + 4]
			MOV BX,0
			PM:
			LEA SI,BUF
			ADD SI,14
			MOV WORD PTR [SI],BX
			INC BX
			CMP BX,CX
			JNZ PM
			
			
			SortExit:
			POPA
			MOV SP,BP
			POP BP
			RETN 4
	SORT ENDP

	;首先压入的参数是成绩表的首地址，之后是人数
	ShowALL PROC NEAR
		;形成栈帧
		PUSH BP
		MOV BP,SP
		
		;保护环境
		PUSHA
		
		
		MOV SI,[BP + 6]
		MOV CX,[BP + 4]
		Show1:
		;SI为成绩表的首地址
		PUSH CX
		PUSH SI
		PUSH SI
		;换行
		LEA DX,CRLF
		MOV AH,09H
		INT 21H
		
		;显示姓名
		LEA DX,STR8
		ADD DX,5
		MOV DI,DX
		MOV CX,9
		CLD
		REP MOVSB
		
		LEA DX,STR8
		POP SI
		MOV AH,09H
		INT 21H
		
		
		;换行
		LEA DX,CRLF
		MOV AH,09H
		INT 21H
		
		;显示成绩和平均成绩 
		LEA AX,[SI + 10]
		LEA DX,[STR9 + 7]
		PUSH AX
		PUSH DX
		CALL IntToString
		
		INC AX
		ADD DX,4
		PUSH AX
		PUSH DX
		CALL IntToString	

		INC AX
		ADD DX,4
		PUSH AX
		PUSH DX
		CALL IntToString
		
		INC AX
		LEA DX,[STR9 + 35]
		PUSH AX
		PUSH DX
		CALL IntToString
		
		LEA DX,STR9
		MOV AH,09H
		INT 21H
			
		;换行
		LEA DX,CRLF
		MOV AH,09H
		INT 21H
		
		LEA SI,STR10
		LEA DI,STR9
		MOV CX,39
		CLD
		REP MOVSB	
		
		
		POP SI
		ADD SI,16
		POP CX
		DEC CX
		JNZ Show1
		
		POPA
		MOV SP,BP
		POP BP
		RETN 4
	ShowALL ENDP

	;第一个参数为字节数据，第二个压入的参数为要写入的位置
	IntToString PROC NEAR
		;形成栈帧
		PUSH BP
		MOV BP,SP
		
		;保护环境
		PUSHA
		
		
		;SI为要写入的位置
		XOR AX,AX
		MOV SI,[BP + 6]
		MOV AL,[SI]
		XOR CX,CX
		;做除法得商和余数，AX放商，DX放余数
		DIVF:
			INC CX
			XOR DX,DX
			MOV BX,0AH
			DIV BX
			PUSH DX
			CMP AX,0
			JNE DIVF
		LEA BX,Temp	
		IntToChar1:
		POP AX
		DEC CX
		ADD AX,'0'
		MOV BYTE PTR [BX],AL
		INC BX
		CMP CX,0
		JNE IntToChar1
		
		LEA SI,Temp
		MOV DI,[BP + 4]
		
		MOV CX,3
		Copy:
		MOV AL,[SI]
		CMP AL,32
		JE CopyE
		MOV [DI],AL
		CopyE:
		INC SI
		INC DI
		DEC CX
		JNZ Copy
		
		LEA SI,Temp1
		LEA DI,Temp
		MOV CX,3
		CLD
		REP MOVSB
		
		POPA
		MOV SP,BP
		POP BP
		
		RETN 4
	IntToString ENDP



	CODES ENDS
		END START