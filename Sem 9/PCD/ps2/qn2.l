%{
#include<stdio.h>

int lineNo = 0; 
%}
  
%%
.*\n       { printf("%03d %s", lineNo++, yytext);}
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