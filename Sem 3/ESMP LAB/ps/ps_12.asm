
; ps 12

org 100h

mov ax, 6000h            
mov ds, ax           
mov si, 0
mov bp, 300h

start:   
    mov ax, 0   
    
    add ax, [si]
    add si,2
    
    add ax, [si]
    add si,2
    
    mov [bp],ax;
    add bp,2
    
    cmp si, 200h
    jl start

ret                                     