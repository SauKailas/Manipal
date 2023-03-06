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
	MOV R2, #2
UP	LDRB R3, [R0], #1
	LDRB R4, [R0], #1
	LSL R3, #4
	ADD R5, R3, R4
	STRB R5, [R1], #1
	SUB R2, #1
	CMP R2, #0
	BNE UP
STOP B STOP
N DCD 0x01020304
	AREA mydata, DATA, READWRITE
DST DCD 0
	END 