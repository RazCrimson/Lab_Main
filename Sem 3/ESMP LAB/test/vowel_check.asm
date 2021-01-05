include emu8086.inc  ; for DEFINE_PRINT_STRING

org 100h

               
; Printing Original string for reference               
LEA si, string    
PRINT "Original String: "
CALL PRINT_STRING
PRINTN ; printing a \n 


LEA si, string ; loading string in si for comparision   
MOV bx, 0
MOV dx, 0

loop_repeat:
                   
     MOV al, [si] ; Moving charater to register for faster comparing
     
     CMP al, 0  ; 
     JZ  end_string_check  
     
     CMP al, 97 ; ASCII value of a is 97
         JL endif                           
        CMP al, 122 ; ASCII value of z is 122
         JG endif
            ; if part
            SUB al, 32   ; Difference between a and A is 32
            MOV [si], al     
         endif:
         
      
      CMP al, 'A'
        JL end_vowel_check
        CMP al, 'Z'
         JG end_vowel_check
         ; if part
         CMP al, 'A'
         JE vowel
         CMP al, 'E'
         JE vowel
         CMP al, 'I'
         JE vowel
         CMP al, 'O'
         JE vowel
         CMP al, 'U'
         JE vowel
         
         ; else part
         ADD dx, 1
         JMP end_vowel_check
         
         vowel:
         ADD bx, 1
         
      end_vowel_check:   
     
     nxt_iteration:
     INC si ; increment si to move to next character
     JMP loop_repeat    ; move to the next iteration
     
end_string_check:  

PRINT "Vowels Count: "
mov ax, bx
call PRINT_NUM
PRINTN

PRINT "Consonants Count: "
mov ax, dx
call PRINT_NUM
PRINTN
  
ret       

string   DB  'aEiOu#*#( dlkjGfNdkfg^#', 0                    

DEFINE_PRINT_STRING  ; for using PRINTN and PRINT_STRING
DEFINE_PRINT_NUM_UNS
DEFINE_PRINT_NUM       
end                       