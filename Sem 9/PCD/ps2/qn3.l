%{
#include<stdio.h>
%}

%x	STRING
%x	COMMENT COMMENT_END
  
%%

 /* Strings */
\"				{ BEGIN STRING; fprintf(yyout, "\""); }
<STRING>\\\"		{ fprintf(yyout, "%s", yytext); }
<STRING>\"		{ BEGIN 0; fprintf(yyout, "%s", yytext); }


 /* Single line comment */
\/\/.* {} 


 /* Multiline comment */
\/\*				{ BEGIN COMMENT;}
<COMMENT>[^\*]		{ }
<COMMENT>\*			{ BEGIN COMMENT_END;}
<COMMENT_END>[^\/]	{ BEGIN COMMENT;}
<COMMENT_END>\/		{ BEGIN 0; }

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
