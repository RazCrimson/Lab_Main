include emu8086.inc

org 100h

list dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

lea si, msgGetCount
call PRINT_STRING 

call scan_num
putc 10

lea si, list

loop_repeat:            
     mov bx, [si + 2]
     mov [si], bx
     add si, 2
     LOOP loop_repeat

      
ret       

msgGetCount   DB  'Enter the number of elements in array: ', 0                    

DEFINE_PRINT_STRING
DEFINE_SCAN_NUM  
           
end            

           