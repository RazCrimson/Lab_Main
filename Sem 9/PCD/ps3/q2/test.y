%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token OPERAND 

%left EQ NE
%left '<' GE '>' LE
%%

program:
    program expr '\n' { printf("Ok\n"); }
    |
    ;

expr:
    OPERAND
    | expr '<' expr 
    | expr '>' expr 
    | expr GE expr
    | expr LE expr 
    | expr EQ expr 
    | expr NE expr 
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