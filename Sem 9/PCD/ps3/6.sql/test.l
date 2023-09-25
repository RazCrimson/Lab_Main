%{
    #include <stdio.h>
    #include "y.tab.h"
    void yyerror(char *s);
%}

letter [a-zA-Z]
digit [0-9]
%%

"as"|"AS" return AS;
"from"|"FROM" return FROM;
"select"|SELECT return SELECT;
"where"|"WHERE" return WHERE;
"group by"|"GROUP BY" return GROUP_BY;
"limit"|"LIMIT" return LIMIT;
"offset"|"OFFSET" return OFFSET;

"<>" return NE;
"<=" return LE;
">=" return GE;
"or"|"OR" return OR;
"and"|"AND" return AND;

{letter}({letter}|{digit})* return IDENTIFIER;
{digit}+ return CONSTANT;

[\+\-\\/*=,;()!] return *yytext;

[ \n\t] ;

%%

void yyerror(char*s){
    printf("%s at lineno %d\n", s, yylineno);
}


int main() {
    yyparse();
    return 0;
}

int yywrap() {
    return 1;
}