%{
#include<stdio.h>
%}

%%

([a-z\+]+:\/\/)([a-z0-9]+\.)+[a-z]{2,6}(\/[A-Za-z0-9]*)*	{ fprintf(yyout, "URL: %s ", yytext); }

%%
  

int main() {   
    yyin = fopen("sample.c", "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    yylex(); 
    return 0;
}

int yywrap(void) { 
    return 1;
}
