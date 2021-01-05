include emu8086.inc  ; for DEFINE_PRINT_STRING

org 100h
      

;mov dx, offset dirpath
;CALL MAKE_DIR
 
;mov dx, offset dirpath
;CALL CHANGE_DIR       

mov dx, offset filepath
mov al, 2
mov cx, 0
CALL MAKE_FILE              


MOV cx, data_size
MOV bx, ax
mov dx, offset text_to_write
CALL WRITE_FILE

    
ret

; Create folder
PROC MAKE_DIR
mov ah, 39h
int 21h
RET
   
; Delete Directory
PROC DELETE_DIR      
mov ah, 3Ah
int 21h
RET
   
; Change Directory
PROC CHANGE_DIR       
mov ah, 3Bh
int 21h
RET

; Create File
PROC MAKE_FILE     
mov ah, 3Ch
int 21h
RET

; Write File
PROC WRITE_FILE     
mov ah, 40h
int 21h
RET
    
; Length Finder    
PROC LEN_FIND
MOV CX, 0 
PUSH AX
    loop_checker_start: 
        MOV al, [si] 
        CMP al, 0
        JE loop_checker_end
        INC DX
        INC CX
        JMP loop_checker_start   
    loop_checker_end:
POP AX
ret 


    


dirpath DB "C:\temp_dir_path", 0 	 
filepath DB "C:\text.txt", 0 	         	
handle DW ?
                                    
text_to_write DB "here is some test text by raz", 0
data_size = $ - offset text_to_write

read_buffer DB data_size

end                       