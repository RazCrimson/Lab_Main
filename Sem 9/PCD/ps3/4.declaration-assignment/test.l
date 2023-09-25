%{
    #include <stdio.h>
    #include "y.tab.h"
%}

letter [a-z]
digit [0-9]
%%

"int" return PRIMITIVE_TYPE;
"char" return PRIMITIVE_TYPE;
"float" return PRIMITIVE_TYPE;
"double" return PRIMITIVE_TYPE;
"void" return VOID;


{letter}({letter}|{digit})* return IDENTIFIER;

{digit}+ return CONSTANT;

[=;\*] return *yytext;

[ \t\n] ;


%%

void yyerror(char* s) {
    printf("%s at line no %d\n", s, yylineno);
}

int yywrap(void) {
    return 1;
}

int main() {
    yyparse();
    return 0;
}
