
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

include emu8086.inc

org 100h

lea si, msgAX
call PRINT_STRING 

call scan_num
mov ax, cx
putc 10

lea si, msgBX
call PRINT_STRING

call scan_num
mov bx, cx
putc 10

cmp ax, 3
jl if_part   
cmp bx, 2
jl if_part

mov cx, 0 
jmp endif

if_part:
mov cx, 1   

endif:   

lea si, msgCX
call PRINT_STRING
mov ax, cx
call PRINT_NUM
putc 10
      
ret
                    
msgAX   DB  'Enter the number for AX: ', 0                    
msgBX   DB  'Enter the number for BX: ', 0                    
msgCX   DB  'The result in CX is : ', 0                    

DEFINE_PRINT_STRING
DEFINE_SCAN_NUM  
DEFINE_PRINT_NUM     
DEFINE_PRINT_NUM_UNS  
end            

lea si, string
mov cx, 0

loop_repeat:
    cmp [si], 0
    jne endif:
    
    endif:
        inc si
        inc cx
    jmp loop_repeat:
loop_end: