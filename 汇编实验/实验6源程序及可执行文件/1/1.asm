;MASMPlus 代码模板 - 控制台程序

.386
.model flat, stdcall
option casemap :none

include windows.inc
include user32.inc
include kernel32.inc
include masm32.inc
include gdi32.inc
include comctl32.inc

includelib gdi32.lib
includelib user32.lib
includelib kernel32.lib
includelib masm32.lib
includelib comctl32.lib
WinMain proto:dword,:dword,:dword,:dword
WndProc proto:dword,:dword,:dword,:dword
TextOut proto:dword,:dword,:dword,:dword
string  proto:dword,:dword
average proto



student struct
			sname db 10 dup(' ')
			chinese db 2 dup(' ')
			english db 2 dup(' ')
			math	  db 2 dup(' ')
			average db 2 dup(' ')
			grade	  db 1 dup(' ')
		student ends
student1 struct
			sname db 10 dup(0)
			chinese db 0
			english db 0
			math	  db 0
			average db 0
			grade	  db 0
		student1 ends
.data
	szDisPlayName db "test1",0
	szEditClass  db "edit",0
	MenuName  db "test2",0
	szClassName db "mainwndclass",0
	aboutmsg  db "IS1602林晓斌",0
	hInstance dd 0
	CommandLine dd 0
	hWnd dd 0
	
	buf1    student1<'yiyi',10,10,10,90,>
	buf2    student1<'erer',20,20,20,90,>
	buf3    student1<'sansan',60,60,60,90,>
	buf4    student1<'sisi',80,80,80,90,>
	buf5    student1<'wuwu',90,90,90,90,>
	buf6	  student<'yiyi','10','10','10','  ',' '>
	buf7    student<'erer','20','20','20','  ',' '>
	buf8    student<'sansan','60','60','60','  ',' '>
	buf9    student<'sisi','80','80','80','  ',' '>
	buf0    student<'wuwu','90','90','90','  ',' '>
	msg_name db 'name',0
	msg_chinese db 'chinese',0
	msg_english db 'english',0
	msg_math db 'math',0
	msg_average db 'average',0
	msg_grade db 'grade',0

	num1=$-msg_name 
	num2=$-msg_chinese
	num3=$-msg_english
	num4=$-msg_math
	num5=$-msg_average
	num6=$-msg_grade
	num7=$-buf1
	num8=$-buf2
	num9=$-buf3
	num10=$-buf4
	num11=$-buf5

	
.CODE
START:
	
	invoke GetModuleHandle,NULL
	mov    hInstance,eax
	INVOKE GetCommandLine
	mov	 CommandLine,eax
	invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
	invoke ExitProcess,eax
	
	;-----------------------main progress-----------
	WinMain proc hInst	:dword,
			  hPrevInst	 	:dword,
			  Cmdline  		:dword,
			  Cmdshow		:dword
			  local wc:WNDCLASSEX
			  local msg1:MSG
			  local wwd:DWORD
			  local wht:DWORD
			  local wtx:DWORD
			  local wty:DWORD
			  local rectclient:RECT			  
			  MOV wc.cbSize,sizeof WNDCLASSEX
			  mov wc.style,CS_HREDRAW + CS_VREDRAW 
			  mov wc.lpfnWndProc,offset WndProc
			  mov wc.cbClsExtra,NULL
			  mov wc.cbWndExtra,NULL
			  push hInst
			  pop wc.hInstance    ;实例句柄赋值
			  mov wc.hbrBackground,COLOR_WINDOW+1   ;color
			  mov wc.lpszMenuName,offset MenuName
			  mov wc.lpszClassName,offset szClassName
			  mov wc.hIcon,0
			  invoke LoadCursor,NULL,IDC_ARROW
			  mov wc.hCursor,eax
			  mov wc.hIconSm,0
			  invoke RegisterClassEx,addr wc
			  mov wwd,600
			  mov wht,400
			  mov wtx,10
			  mov wty,10
			  invoke CreateWindowEx,WS_EX_ACCEPTFILES+WS_EX_APPWINDOW,addr szClassName,addr szDisPlayName,WS_OVERLAPPEDWINDOW+WS_VISIBLE,wtx,wty,wwd,wht,NULL,NULL,hInst,NULL   ;创建可视窗口（hInst好像没定义）
			  mov hWnd,eax
			  invoke LoadMenu,hInst,600
			  invoke SetMenu,hWnd,eax
			  ;消息循环
StartLoop: invoke GetMessage,addr msg1,NULL,0,0
			  cmp eax,0
			  je ExitLoop
			  invoke TranslateMessage,addr msg1
			  invoke DispatchMessage,addr msg1
			  jmp StartLoop
			  ExitLoop:
			  mov eax,1000
			  ret
			  WinMain endp 

			  ;用户处理程序
			  ;按行打印msg_，buf数据段表示方式有待考量
			  showlist proc 
			  	LOCAL hdc: HDC
			  	push eax
			  	invoke GetDC,hWnd
			  	mov hdc,eax
			  	invoke TextOut,hdc,10,10,addr msg_name,4
			  	invoke TextOut,hdc,110,10,addr msg_chinese,7
			  	invoke TextOut,hdc,210,10,addr msg_english,7
			  	invoke TextOut,hdc,310,10,addr msg_math,4
			  	invoke TextOut,hdc,410,10,addr msg_average,7
			  	invoke TextOut,hdc,510,10,addr msg_grade,5
			  	
            invoke TextOut,hdc,10,30,ADDR buf6.sname,10
 				invoke TextOut,hdc,110,30,ADDR buf6.chinese,2
  				invoke TextOut,hdc,210,30,ADDR buf6.english,2
  				invoke TextOut,hdc,310,30,ADDR buf6.math,2
  				invoke TextOut,hdc,410,30,ADDR buf6.average,2
  				invoke TextOut,hdc,510,30,ADDR buf6.grade,1
  
  				invoke TextOut,hdc,10,50,ADDR buf7.sname,10
  				invoke TextOut,hdc,110,50,ADDR buf7.chinese,2
  				invoke TextOut,hdc,210,50,ADDR buf7.english,2
  				invoke TextOut,hdc,310,50,ADDR buf7.math,2
  				invoke TextOut,hdc,410,50,ADDR buf7.average,2
  				invoke TextOut,hdc,510,50,ADDR buf7.grade,1
  
  				invoke TextOut,hdc,10,70,ADDR buf8.sname,10
  				invoke TextOut,hdc,110,70,ADDR buf8.chinese,2
  				invoke TextOut,hdc,210,70,ADDR buf8.english,2
  				invoke TextOut,hdc,310,70,ADDR buf8.math,2
  				invoke TextOut,hdc,410,70,ADDR buf8.average,2
  				invoke TextOut,hdc,510,70,ADDR buf8.grade,1
  
  				invoke TextOut,hdc,10,90,ADDR buf9.sname,10
  				invoke TextOut,hdc,110,90,ADDR buf9.chinese,2
  				invoke TextOut,hdc,210,90,ADDR buf9.english,2
  				invoke TextOut,hdc,310,90,ADDR buf9.math,2
  				invoke TextOut,hdc,410,90,ADDR buf9.average,2
  				invoke TextOut,hdc,510,90,ADDR buf9.grade,1
  
  				invoke TextOut,hdc,10,110,ADDR buf0.sname,10
  				invoke TextOut,hdc,110,110,ADDR buf0.chinese,2
  				invoke TextOut,hdc,210,110,ADDR buf0.english,2
 				invoke TextOut,hdc,310,110,ADDR buf0.math,2
  				invoke TextOut,hdc,410,110,ADDR buf0.average,2
  				invoke TextOut,hdc,510,110,ADDR buf0.grade,1
			  	pop eax
			  	
			  	ret
			  	showlist endp
			  	
			  	string proc bufa:DWORD, bufb:DWORD  

			   push eax
            push dx
            push di
			   PUSH EBX
			   MOV EAX,bufb
            mov al,BYTE ptr[EAX]
			   mov ah,0
			   mov dx,0
            MOV DI,10
            DIV DI
            ADD AL,30H
			   MOV EBX,bufa
            MOV BYTE ptr [EBX],AL
            ADD DL,30H
            MOV BYTE ptr [EBX+1],DL
			   POP EBX
			  	pop di
			  	pop dx
			  	pop eax
			  	ret
			  	string endp
			  		
			  		
			  	average proc
			  		push ax
			  		push bx
			  		push ecx
			  		push esi
			  		push edi
			  		mov bl,3
			  		xor ax,ax
			  		mov al,buf1.chinese
			  		add al,buf1.english
			  		add al,buf1.math
			  		div bl
			  		mov buf1.average,al
			  		invoke string,addr buf6.average,addr buf1.average
			  		mov al,buf2.chinese
			  		add al,buf2.english
			  		add al,buf2.math
			  		div bl
			  		mov buf2.average,al
			  		invoke string,addr buf7.average,addr buf2.average
			  		mov al,buf3.chinese
			  		add al,buf3.english
			  		add al,buf3.math
			  		div bl
			  		mov buf3.average,al
			  		invoke string,addr buf8.average,addr buf3.average
			  		mov al,buf4.chinese
			  		add al,buf4.english
			  		add al,buf4.math
			  		div bl
			  		mov buf4.average,al
			  		invoke string,addr buf9.average,addr buf4.average
			  		mov al,buf5.chinese
			  		add al,buf5.english
			  		mov ah,0
			  		mov cl,buf5.math
			  		mov ch,0
			  		add ax,cx
			  		div bl
			  		mov buf5.average,al
			  		invoke string,addr buf0.average,addr buf5.average
			  		mov ecx,0
			  		mov esi,0
			  		mov edi,0
		lp:	   cmp buf1[edi].average,90
			  		jge level1  
			  		cmp buf1[edi].average,80
			  		jge level2
			  		cmp buf1[edi].average,70
			  		jge level3
			  		jmp level4
		level1:  mov al,'A'
		         mov BYTE ptr buf6[esi].grade,al
		         jmp quit
		level2:  mov al,'B'
		         mov BYTE ptr buf6[esi].grade,al
		         jmp quit
		level3:  mov al,'C'
					mov BYTE ptr buf6[esi].grade,al
		         jmp quit
		level4:  mov al,'D'
					mov BYTE ptr buf6[esi].grade,al
		         jmp quit
		quit:    inc ecx
		         add esi,19
		         add edi,15
		         cmp ecx,5
		         jle lp
		         pop edi
		         pop esi
		         pop ecx
		         pop bx
		         pop ax
			  		ret
			  	average endp
			  	
			;窗口消息处理程序
			
			WndProc proc hWin     :dword,
				uMsg	   :dword,
				wParam	:dword,
				lParam   :dword
				.if uMsg == WM_COMMAND
					.if wParam ==3000
						invoke showlist   ;待完善showlist
						.elseif wParam ==2000
							invoke average    ;待完善average
							.elseif wParam == 4000
								invoke MessageBox,hWin,addr aboutmsg,addr szDisPlayName,MB_OK
								.elseif wParam ==1000
									invoke ExitProcess,0
							.endif
			        .elseif uMsg ==WM_DESTROY
			   	       invoke PostQuitMessage,NULL
			        .else 
			             invoke DefWindowProc,hWin,uMsg,wParam,lParam
			   	        ret
			   .endif
			   mov eax,0
			   ret
			  WndProc endp
			 
			  	
	
	
	;暂停显示,回车键关闭
	
	invoke ExitProcess,0
	
end START