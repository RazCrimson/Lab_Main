%{
    #include <stdlib.h>
    #include "nodeTypes.h"
    #include "y.tab.h"

    void yyerror(char *);
%}

%%
[0-9]+ {
    yylval.iValue = atoi(yytext);
    return CONSTANT;
}

[a-z]   {
    yylval.sIndex = *yytext - 'a';
    return VARIABLE;
} 

[=\+\-\*\/<>(){}!;:] return *yytext;

"if" return IF;
"else" return ELSE;
"while" return WHILE;
"print" return PRINT;
"switch" return SWITCH;
"case" return CASE;
"default" return DEFAULT;


"<=" return LE;
">=" return GE;
"==" return EQ;
"!=" return NE;
"&&" return AND;
"||" return OR;


[ \t\n] ; /* Skip Whitespaces */

. yyerror("invalid character");

%%

void yyerror(char *s) {
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}  

int yywrap(void) {
    return 1;
}