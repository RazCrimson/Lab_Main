include emu8086.inc  ; for DEFINE_PRINT_STRING

org 100h

               
; Printing Original string for reference               
LEA si, string    
PRINT "Original String: "
CALL PRINT_STRING
PRINTN ; printing a \n 


LEA si, string ; loading string in si for comparision   
MOV bx, 1 ; bx acts a as flag for detecting start of a new word

loop_repeat:
                   
     MOV al, [si] ; Moving charater to register for faster comparing
     
     CMP al, 0  ; 
     JZ  end_string_check  
     
     CMP bx, 0
     JE endif
         ; Doing a check of small char only if we had a space character
         ; in the previous iteration
         MOV bx, 0
                                  
         CMP al, 97 ; ASCII value of a is 97
         JL endif                           
         CMP al, 122 ; ASCII value of z is 122
         JG endif
            ; if part
            SUB al, 32   ; Difference between a and A is 32
            MOV [si], al     
         endif:
                        
     CMP al, 32    ; ASCII value for space character
     JNZ  no_space_char   
        MOV bx, 1
        JMP nxt_iteration            
     no_space_char:
        MOV bx, 0    
     
     nxt_iteration:
     INC si ; increment si to move to next character
     JMP loop_repeat    ; move to the next iteration
     
end_string_check:

      
; Printing Modified string for reference      
LEA si, string    
PRINT "Current String: "
CALL PRINT_STRING
PRINTN ; printing a \n  
  
ret       

string   DB  'tHIS IS a tEST, dummy string', 0                    

DEFINE_PRINT_STRING  ; for using PRINTN and PRINT_STRING
       
end                       