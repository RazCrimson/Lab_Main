
; ps 5

org 100h

mov bx, 7000

jmp SHIFT

INCREMENT_COUNT:
    inc cx
    jmp POST_INCREMENT

SHIFT:
    mov ax,[bx]
    shr ax,1
    jnc INCREMENT_COUNT
POST_INCREMENT:   
    inc bx
    inc cx
    cmp bx,8000
    JGE SHIFT

ret          

