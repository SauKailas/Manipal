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
	LDR R1, [R0]
	LDR R2, =DST
	MOV R3, #1
UP	MUL R3, R3, R1
	SUB R1, R1, #1
	CMP R1, #0
	BNE UP
	STR R3, [R2]
STOP B STOP
N DCD 5
	AREA mydata, DATA, READWRITE
DST DCD 0
	END