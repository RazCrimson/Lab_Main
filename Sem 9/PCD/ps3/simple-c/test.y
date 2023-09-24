%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "nodeTypes.h"

    nodeType* allocNode(size_t additionalSize);
    nodeType* addConstant(int val);
    nodeType* addIdentifier(int i);
    nodeType* addOperation(int oper, int nops, ...);
    void freeNode(nodeType *p);
    int exec(nodeType *p);

    int yylex(void);
    void yyerror(char *s);

    int sym[26];
%}
%union {
    int iValue;
    char sIndex;
    nodeType *nodePtr;
};

%token <iValue> CONSTANT
%token <sIndex> VARIABLE
%token WHILE IF PRINT

%nonassoc IFX
%nonassoc ELSE

%right '='
%right '!'
%left OR
%left AND
%left EQ NE
%left '<' GE '>' LE
%left '+' '-'
%left '*' '/'

%nonassoc UMINUS

%type <nodePtr> stmt expr stmt_list loop conditional

%% program:
    function { exit(0); }
    ;

function:
    function stmt { exec($2); freeNode($2); }
    |
    ;   

stmt:
    ';' { $$ = addOperation(';', 2, NULL, NULL); }
    | expr ';' { $$ = $1; }
    | PRINT expr ';' { $$ = addOperation(PRINT, 1, $2); }
    | VARIABLE '=' expr ';' { $$ = addOperation('=', 2, addIdentifier($1), $3); }
    | '{' stmt_list '}' { $$ = $2; }
    | loop
    | conditional
    ;

loop: 
    WHILE '(' expr ')' stmt { $$ = addOperation(WHILE, 2, $3, $5); }
    ;

conditional:
    IF '(' expr ')' stmt %prec IFX { $$ = addOperation(IF, 2, $3, $5); }
    | IF '(' expr ')' stmt ELSE stmt { $$ = addOperation(IF, 3, $3, $5, $7); }
    ;

stmt_list:
    stmt { $$ = $1; }
    | stmt_list stmt { $$ = addOperation(';', 2, $1, $2); }
    ;

expr:
    CONSTANT { $$ = addConstant($1); }
    | VARIABLE { $$ = addIdentifier($1); }
    | '!' expr { $$ = addOperation('!', 1, $2); }
    | '-' expr %prec UMINUS { $$ = addOperation(UMINUS, 1, $2); }
    | expr '+' expr { $$ = addOperation('+', 2, $1, $3); }
    | expr '-' expr { $$ = addOperation('-', 2, $1, $3); }
    | expr '*' expr { $$ = addOperation('*', 2, $1, $3); }
    | expr '/' expr { $$ = addOperation('/', 2, $1, $3); }
    | expr '<' expr { $$ = addOperation('<', 2, $1, $3); }
    | expr '>' expr { $$ = addOperation('>', 2, $1, $3); }
    | expr GE expr { $$ = addOperation(GE, 2, $1, $3); }
    | expr LE expr { $$ = addOperation(LE, 2, $1, $3); }
    | expr NE expr { $$ = addOperation(NE, 2, $1, $3); }
    | expr EQ expr { $$ = addOperation(EQ, 2, $1, $3); }
    | expr OR expr { $$ = addOperation(OR, 2, $1, $3); }
    | expr AND expr { $$ = addOperation(AND, 2, $1, $3); }
    | '(' expr ')' { $$ = $2; }
    ;

%%

nodeType* allocNode(size_t additionalSize)
{
    nodeType *p;
    size_t nodeSize = ((char *)&p->con - (char *)p) + additionalSize;
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    return p;
}

nodeType* addConstant(int val)
{
    nodeType *p = allocNode(sizeof(conNodeType));

    // Copy info
    p->type = T_CONSTANT;
    p->con.value = val;
    return p;
}

nodeType* addIdentifier(int i)
{
    nodeType *p = allocNode(sizeof(idNodeType));

    // Copy info
    p->type = T_IDENTIFIER;
    p->id.i = i;
    return p;
}

nodeType* addOperation(int oper, int nops, ...)
{
    nodeType *p = allocNode(sizeof(oprNodeType) + nops * sizeof(nodeType *));

    // Copy info
    p->type = T_OPERATION;
    p->opr.oper = oper;
    p->opr.nops = nops;

    va_list arg_ptr;
    va_start(arg_ptr, nops);
    for (int i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(arg_ptr, nodeType*);
    va_end(arg_ptr);
    return p;
}


void freeNode(nodeType *p)
{
    int i;
    if (!p)
        return;
    if (p->type == T_OPERATION)
    {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free(p);
}


int main(void)
{
    yyparse();
    return 0;
}


int exec(nodeType *p)
{
    if (!p)
        return 0;
    switch (p->type)
    {
    case T_CONSTANT:
        return p->con.value;
    case T_IDENTIFIER:
        return sym[p->id.i];
    case T_OPERATION:

        switch (p->opr.oper)
        {
        case WHILE:
            while (exec(p->opr.op[0]))
                exec(p->opr.op[1]);
            return 0;
        case IF:
            if (exec(p->opr.op[0]))
                exec(p->opr.op[1]);
            else if (p->opr.nops > 2)
                exec(p->opr.op[2]);
            return 0;
        case PRINT:
            printf("%d\n", exec(p->opr.op[0]));
            return 0;
        case ';':
            exec(p->opr.op[0]);
            return exec(p->opr.op[1]);
        case '=':
            return sym[p->opr.op[0]->id.i] = exec(p->opr.op[1]);
        case '!':
            return !exec(p->opr.op[0]);
        case UMINUS:
            return -exec(p->opr.op[0]);
        case '+':
            return exec(p->opr.op[0]) + exec(p->opr.op[1]);
        case '-':
            return exec(p->opr.op[0]) - exec(p->opr.op[1]);
        case '*':
            return exec(p->opr.op[0]) * exec(p->opr.op[1]);
        case '/':
            return exec(p->opr.op[0]) / exec(p->opr.op[1]);
        case '<':
            return exec(p->opr.op[0]) < exec(p->opr.op[1]);
        case '>':
            return exec(p->opr.op[0]) > exec(p->opr.op[1]);
        case GE:
            return exec(p->opr.op[0]) >= exec(p->opr.op[1]);
        case LE:
            return exec(p->opr.op[0]) <= exec(p->opr.op[1]);
        case NE:
            return exec(p->opr.op[0]) != exec(p->opr.op[1]);
        case EQ:
            return exec(p->opr.op[0]) == exec(p->opr.op[1]);
        case OR:
            return exec(p->opr.op[0]) || exec(p->opr.op[1]);
        case AND:
            return exec(p->opr.op[0]) && exec(p->opr.op[1]);
        }
    }
    return 0;
}