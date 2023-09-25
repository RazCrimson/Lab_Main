%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char * s);

%}

%token PRIMITIVE_TYPE CONSTANT IDENTIFIER VOID
%%

program:
    program stmt { printf("Ok\n");}
    |

stmt:
    declaration ';'
    | assignment ';'


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
