[bits 16]
[CPU 8086]


    global _start
    section .text

_start:
MOV AL, 0xff
MOV AX, 0xff00
MOV BX, 100
MOV CX, 1210

CMP AX, BX 

JGE AX_GREATER
    MOV DX,BX
    JMP SECOND_CMP
AX_GREATER:
    MOV DX,AX
    
SECOND_CMP:
CMP DX, CX
JGE DX_GREATER
   MOV DX, CX
   
DX_GREATER:    

HLT

times 510-($-$$) db 0x00
dw 0xAA55