	AREA RESET, DATA, READONLY
	EXPORT _Vectors
_Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R1, =DST
	MOV R2, #10
	ADD R0, R0, #36
UP 	LDR R3, [R0]
	STR R3, [R1]
	SUB R0, R0, #4
	ADD R1, R1, #4
	SUB R2, R2, #1
	CMP R2, #0
	BNE UP
STOP B STOP
SRC DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	AREA mydata, DATA, READWRITE
DST DCD 0
	END