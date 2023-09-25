%{
    #include <stdio.h>
    void yyerror(char*s);
    int yylex();
%}

%token PRIMITIVE_TYPE VOID IDENTIFIER CLASS ACCESS CONSTANT
%%

program:
    program class { printf("Ok\n");}
    | 
    ;

class:
    CLASS IDENTIFIER inherit_or_not '{' class_definition '}' ';' 

inherit_or_not:
    ':' inhertance_chain
    |
    ;

inheritance_item:
    IDENTIFIER
    | ACCESS IDENTIFIER


inhertance_chain:
    inheritance_item
    | inhertance_chain ',' inheritance_item
    ;

class_definition:
    stmt_list
    | 
    ;

stmt_list:
    stmt
    | stmt_list stmt
    ;

stmt: 
    ACCESS ':'
    | function
    | declaration ';'
    | assignment ';'
    | '{' stmt_list '}'
    ;



function:
    data_type IDENTIFIER params_or_no_param ';'
    | data_type IDENTIFIER params_or_no_param '{' '}'
    | VOID IDENTIFIER params_or_no_param ';'
    | VOID IDENTIFIER params_or_no_param '{' '}'
    ;
    

params_or_no_param:
    '(' parameters ')'
    | '(' ')'

parameters:
    data_type IDENTIFIER
    | parameters ',' data_type IDENTIFIER
    ;

declaration:
    data_type IDENTIFIER
    | declaration '=' rvalue 

data_type:
    PRIMITIVE_TYPE
    | VOID '*'
    | data_type '*'
    ;

assignment:
    lvalue '=' rvalue

lvalue:
    IDENTIFIER
    | '*' lvalue

rvalue:
    lvalue
    | CONSTANT
%%
