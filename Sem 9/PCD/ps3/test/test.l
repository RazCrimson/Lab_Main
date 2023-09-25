%{
    #include "nodeTypes.h"
    #include "y.tab.h"
    void yyerror(char * s);
%}
%%

[0-9]+ { yylval.value = atoi(yytext); return CONSTANT; }
[a-z]  { yylval.symIndex = *yytext - 'a'; return VARIABLE; }

[\+\-\*\/\(\)<>:;={}] return *yytext;

"print" return PRINT;
"if" return IF;
"else" return ELSE;
"while" return WHILE;

[ \t\n] ;

%%

void yyerror(char *s) {
    printf("%s at lineno: %d\n", s, yylineno);
}

int yywrap(void){
    return 1;
}

int main() {
    yyparse();
    return 0;
}