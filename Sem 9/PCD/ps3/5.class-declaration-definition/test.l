%{
    #include <stdio.h>
    #include "y.tab.h"
%}

letter [a-zA-Z_]
digit [0-9]

%%

"int" return PRIMITIVE_TYPE;
"float" return PRIMITIVE_TYPE;
"char" return PRIMITIVE_TYPE;
"double" return PRIMITIVE_TYPE;
"void" return VOID;
"class" return CLASS;

"private" return ACCESS;
"public" return ACCESS;
"protected" return ACCESS;


{letter}({letter}|{digit})* return IDENTIFIER;
{digit}+ return CONSTANT;

[\*=,:;{}()] return *yytext;

[ \n\t] ;

%%


void yyerror(char* s) {
        printf("%s at lineno: %d", s, yylineno);
}

int yywrap(void) {
    return 1;
}

int main() {
    yyparse();
    return 0;
}