%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token OPERAND

%%

program:
    program expr '\n' { printf("Ok\n"); }
    |
    ;

expr:
    OPERAND
    | expr '+' expr 
    | expr '-' expr 
    | expr '*' expr 
    | expr '/' expr 
    | expr '(' expr ')' 
    | '(' expr ')' expr 
    | '(' expr ')' 
    | '-' expr 
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}    

int main(void) {
    yyparse();
    return 0;
}