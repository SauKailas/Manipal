	AREA RESET, DATA, READONLY
	EXPORT _Vectors
_Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =N1
	LDR R1, [R0]
	LDR R0, =N2
	LDR R2, [R0]
	ADDS R3, R1, R2
	LDR R4, =DST
	STR R3, [R4]
STOP B STOP
N1 DCD 0x1234
N2 DCD 0x4321
	AREA mydata, DATA, READWRITE
DST DCD 0
	END