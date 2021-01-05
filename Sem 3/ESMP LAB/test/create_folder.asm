include emu8086.inc  ; for DEFINE_PRINT_STRING

org 100h
      
; Create folder      
mov dx, offset filepath
mov ah, 39h
int 21h
JNC end_change
       

; Delete folder
mov dx, offset filepath
mov ah, 3Ah
int 21h       

end_change:       
ret

filepath DB "C:\mydir", 0 	; path to be created. 


end                       