; ps 8

org 100h
         
mov si, 800h
               
; Random inputs               
mov [si + 1], 10h
mov [si + 5], 52h

mov dx,[si]
mov ax, dx
mov bx, dx   
add si, 2
    
MIN_MAX:
    mov dx,[si]
    
    cmp dx,ax
    jle SKIP_MAX
        mov ax, dx
    SKIP_MAX:
    
    cmp bx,dx
    jle SKIP_MIN
        mov bx, dx
    SKIP_MIN:
    
    add si, 2
    cmp si, 80ah 
    jl MIN_MAX

ret           