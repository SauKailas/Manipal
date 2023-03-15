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
	AND R2, #0xF0
	LSR R2, #4
	CMP R2, #0xA
	BCC LESS1
	ADD R2, #0x7
LESS1	
	ADD R2, #0x30
	STRB R2, [R1], #1
	LDR R2, [R0]
	AND R2, #0x0F
	CMP R2, #0xA
	BCC LESS2
	ADD R2, #0x7
LESS2 	
	ADD R2, #0x30
	STRB R2, [R1]
STOP B STOP
N DCD 0xA1
	AREA mydata, DATA, READWRITE
DST DCD 0
	END