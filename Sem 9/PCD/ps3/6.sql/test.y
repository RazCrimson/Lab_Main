%{
    #include <stdio.h>
    int yylex();
    void yyerror();

%}

%token SELECT FROM AS IDENTIFIER CONSTANT WHERE GROUP_BY LIMIT OFFSET
%token GE LE NE

%left '!'
%left AND OR
%left '=' NE
%left GE LE '<' '>'
%left '+' '-'
%left '*' '/'

%%
queries:
    queries query {printf("Ok\n");}
    |
    ;

query:
    subquery ';'

subquery:
    SELECT projection FROM table_clause where_clause groupby_clause limit_clause offset_clause 

projection:
    | '*'
    | as_clause
    | projection ',' as_clause
    ;

table_clause:
    as_clause
    ;

as_clause:
    IDENTIFIER
    | IDENTIFIER AS IDENTIFIER
    ;


where_clause:
    WHERE expr
    |
    ;

expr:
    | '!' operand
    | operand '+' operand
    | operand '-' operand
    | operand '*' operand
    | operand '/' operand
    | operand '<' operand
    | operand '>' operand
    | operand GE operand
    | operand LE operand
    | operand NE operand
    | operand '=' operand
    | operand OR operand
    | operand AND operand
    | '(' operand ')'
    | '(' subquery ')'
    ;

operand:
    expr
    | CONSTANT
    | IDENTIFIER
    ;

groupby_clause:
    GROUP_BY identifiers
    |
    ;

identifiers:
    IDENTIFIER
    | identifiers ',' IDENTIFIER
    ;

limit_clause:
    LIMIT CONSTANT
    |
    ;

offset_clause:
    OFFSET CONSTANT
    |
    ;










%%