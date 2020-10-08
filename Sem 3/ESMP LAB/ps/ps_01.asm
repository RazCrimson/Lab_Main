; ps 1

org 100h

mov bp, 1000h
mov si, 0100h


mov [bp][si], 100
mov bx, [bp][si]
mov cx, bx
mov [1300h], cx

ret




