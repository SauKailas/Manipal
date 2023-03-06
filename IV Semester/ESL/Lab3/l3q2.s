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
	MLA R3, R1, R1, R1
	LSR R3, #1
	STR R3, [R2]
STOP B STOP
N DCD 5
	AREA mydata, DATA, READWRITE
DST DCD 0
	END