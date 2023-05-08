	AREA RESET, DATA, READONLY
	EXPORT _Vectors
_Vectors
	DCD 0x10001000;
	DCD Reset_Handler;
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #10
	LDR R1, =SRC
	LDR R2, =DST
UP 	LDR R3, [R1], #4
	STR R3, [R2], #4
	SUBS R0, R0, #1
	CMP R0, #0
	BNE UP
STOP B STOP
SRC DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
	