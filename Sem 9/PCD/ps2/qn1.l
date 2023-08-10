%{
#include<stdio.h>

int alpha, digits, spaces, special, lines, words; 
alpha = 0;
digits = 0;
spaces = 0;
special = 0;
lines = 0;
words = 0;

%}
  
%%
[a-zA-Z]+       {words++; alpha += yyleng;}
[0-9]           {digits++;} 
[ \t]           {spaces++;} 
\n              {lines++;}
.               {special++;}  // Ignore other charaters
%%
  

int main() {   
    yyin = fopen("sample.c", "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }
    // The function that starts the analysis
    yylex();
    printf("Number of alphabets: %d\n", alpha);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);
    printf("Number of special: %d\n", special);
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
  
    return 0;
}

int yywrap(void) { 
    return 1;
}