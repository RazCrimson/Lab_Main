%{
    #include <stdlib.h>
    #include "y.tab.h"
    void yyerror(char *);
%}

%%
[0-9a-zA-Z]+ return OPERAND; 

[-+\*\/\(\)\n] return *yytext;

[ \t] ; /* skip whitespace */

. yyerror("invalid character");

%%

int yywrap(void) {
    return 1;
}