include emu8086.inc  ; for DEFINE_PRINT_STRING

org 100h

               
PRINT "Enter the number : "
CALL SCAN_NUM  
PRINTN



MOV AX, 0

loop_repeat:   


      SHL CX, 1
      JC PRINT1
        PUSH 0             
        JMP  nxt_iteration
      PRINT1:                 
        PUSH 1                          
        
     
     
     nxt_iteration:
     ADD AX, 1
     CMP AX, 16
     JL loop_repeat    ; move to the next iteration
     
end_loop:  

ret       

DEFINE_PRINT_STRING  ; for using PRINTN and PRINT_STRING
DEFINE_SCAN_NUM        
end                       