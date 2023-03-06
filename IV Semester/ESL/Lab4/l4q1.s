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
	LDR R0, =N
	LDR R1, =DST
	LDR R2, [R0]
	MOV R3, #0xA
	MOV R7, #0xF
	MOV R4, #0
	MOV R5, #1
UP 	MOV R6, R2
	AND R6, R7
	MLA R4, R6, R5, R4
	MUL R5, R3
	LSR R2, #4
	CMP R2, #0
	BNE UP
	STR R4, [R1]
STOP B STOP
N DCD 0x35
	AREA mydata, DATA, READWRITE
DST DCD 0	
	END