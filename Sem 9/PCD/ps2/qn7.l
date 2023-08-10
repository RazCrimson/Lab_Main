%{
#include<stdio.h>
%}

IP_OCTET 25[0-5]|((2[0-4]|1[0-9]|[1-9])[0-9]?)
MAC_BYTE [0-9a-fA-F][0-9a-fA-F]
%%

({IP_OCTET}\.){3}{IP_OCTET}	{ fprintf(yyout, "IP Address: %s ", yytext); }

({MAC_BYTE}[\-:]){5}{MAC_BYTE}  { fprintf(yyout, "MAC Address: %s ", yytext); }

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
