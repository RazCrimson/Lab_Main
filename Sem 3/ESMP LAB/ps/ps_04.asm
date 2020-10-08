org 100h

Mov Dx, 63
Mov Cx, 0

Jmp Start 

Increment:
    Inc Cx   

Start:
    Shr Dx, 1
    Jc Increment
    Cmp Dx, 0
    Jg Start     

ret