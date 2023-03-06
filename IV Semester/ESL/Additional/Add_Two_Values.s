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
	MOV R0, #1
	MOV R1, #2
	ADD R2, R0, R1
	END