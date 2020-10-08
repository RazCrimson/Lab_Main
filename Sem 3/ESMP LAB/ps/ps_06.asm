
; ps 6

org 100h

mov AL, 0
mov bx, 1200h
mov cx, 0  

jmp SHIFT

INCREMENT:
    inc cx
    inc BX
    JMP post_inc

SHIFT:   
    CMP AL,[BX]
    JE INCREMENT
    INC BX 
    post_inc:
    CMP bx, 1250h
    JLE SHIFT  

ret