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
	MOV R3, #0
UP 	LDR R4, [R0]
	ADDS R3, R3, R4
	ADD R0, #4
	SUB R2, R2, #1
	CMP R2, #0
	BNE UP
	STR R3, [R1]
STOP B STOP
SRC DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	AREA mydata, DATA, READWRITE
DST DCD 0
	END