
; ps 11

org 100h
            
mov si, 800h
mov bx, 900h
mov bp, 950h


jmp start

ARRPOS:
    mov [bp],dh
    inc bp
    jmp continue
    
ARRNEG:
    mov [bx],dh
    inc bx
    jmp continue


start:
    mov dh,[si]
    cmp dh, 0
    jg ARRPOS
    jl ARRNEG
    inc dl
    continue:
    inc si
    cmp si, 80ah
    jl start 


ret                                     