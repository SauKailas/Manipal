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
	MOV R0, #15
	LDR R1, =DST
	STR R0, [R1]
STOP B STOP
	AREA mydata, DATA, READWRITE
DST DCD 0
	END