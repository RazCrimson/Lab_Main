
; ps 8

org 100h

mov ax, 5
mov cx, 0
mov si, 600h
mov di, 700h


SAME_ORDER:
    mov bl,[si]
    mov [di], bl
    cmp bl, 99h
    jle skip1:
    call INCREMENT
    skip1:
    inc di
    inc si
    inc cx
    cmp cx, ax 
    jl SAME_ORDER
                

mov di,800h              
            
  
REVERSE_ORDER:
    dec si
    mov bl,[si]
    mov [di], bl
    cmp bl, 99h
    jle skip2:
    call INCREMENT
    skip2:
    inc di
    inc cx
    cmp cx, ax 
    jl REVERSE_ORDER

ret          

INCREMENT:
    inc cx
    ret

