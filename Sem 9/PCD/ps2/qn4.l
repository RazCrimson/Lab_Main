%{
#include<stdio.h>
%}

%x	STRING
  
%%

 /* Strings */
\"				{ BEGIN STRING; fprintf(yyout, "\""); }
<STRING>\\\"		{ fprintf(yyout, "%s", yytext); }
<STRING>\"		{ BEGIN 0; fprintf(yyout, "%s", yytext); }


[ ]+	{ fprintf(yyout, " "); }
\t+	{ fprintf(yyout, "\t"); }
\n+	{ fprintf(yyout, "\n"); }

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
