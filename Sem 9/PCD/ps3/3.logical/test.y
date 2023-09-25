%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token OPERAND 

%right '!'
%left OR
%left AND
%%

program:
    program expr '\n' { printf("Ok\n"); }
    |
    ;

expr:
    OPERAND
    | expr AND expr
    | expr OR expr 
    | '!' expr
    | '(' expr ')' 
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}    

int main(void) {
    yyparse();
    return 0;
}