%{
    #include <stdio.h>
    #include <stdarg.h>
    #include "nodeTypes.h"

    Node* allocNode();
    Node* addConstant(int value);
    Node* addIdentifier(char symIndex);
    Node* addOperation(int operator, int operandCount, ...);
    int execute(Node* node);

    int yylex(void);
    void yyerror(char* s);


    int sym[26];

%}

%union {
    int value;
    char symIndex;
    Node* nodePtr;
};

%token <value> CONSTANT
%token <symIndex> VARIABLE

%token PRINT IF ELSE WHILE

%nonassoc IFX
%nonassoc ELSE

%right '='
%left OR 
%left AND
%right '!'
%left EQ NE
%left GE LE '<' '>' 
%left '+' '-'
%left '*' '/' '%'

%nonassoc UMINUS

%type <nodePtr> stmt stmt_list expr conditional loop
%%
program:
    program stmt { execute($2); }
    |

stmt:
    ';' { $$ = NULL; }
    | expr ';' { $$ = $1; }
    | '{' stmt_list '}' { $$ = $2;}
    | '{' '}' { $$ = NULL; }
    | PRINT expr ';' { $$ = addOperation(PRINT, 1, $2); }
    | conditional
    | loop
    ;
    

stmt_list:
    stmt { $$ = $1; }
    | stmt_list stmt { $$ = addOperation(';', 2, $1, $2); }
    ;

conditional:
    IF '(' expr ')' stmt %prec IFX { $$ = addOperation(IF, 3, $3, $5, NULL);}
    | IF '(' expr ')' stmt ELSE stmt { $$ = addOperation(IF, 3, $3, $5, $7);}

loop:
    WHILE '(' expr ')' stmt {$$ = addOperation(WHILE, 2, $3, $5);}

expr:
    CONSTANT { $$ = addConstant($1); }
    | VARIABLE { $$ = addIdentifier($1); }
    | VARIABLE '=' expr { $$ = addOperation('=', 2, addIdentifier($1), $3); }
    | '!' expr { $$ = addOperation('!', 1, $2); }
    | '-' expr %prec UMINUS { $$ = addOperation(UMINUS, 1, $2); }
    | expr '+' expr { $$ = addOperation('+', 2, $1, $3); }
    | expr '-' expr { $$ = addOperation('-', 2, $1, $3); }
    | expr '*' expr { $$ = addOperation('*', 2, $1, $3); }
    | expr '/' expr { $$ = addOperation('/', 2, $1, $3); }
    | expr '%' expr { $$ = addOperation('%', 2, $1, $3); }
    | expr OR expr { $$ = addOperation(OR, 2, $1, $3); }
    | expr AND expr { $$ = addOperation(AND, 2, $1, $3); }
    | expr EQ expr { $$ = addOperation(EQ, 2, $1, $3); }
    | expr NE expr { $$ = addOperation(NE, 2, $1, $3); }
    | expr GE expr { $$ = addOperation(GE, 2, $1, $3); }
    | expr LE expr { $$ = addOperation(LE, 2, $1, $3); }
    | expr '<' expr { $$ = addOperation('<', 2, $1, $3); }
    | expr '>' expr { $$ = addOperation('>', 2, $1, $3); }
    | '(' expr ')' { $$ = $2; }
    ;  

%%

Node* allocNode() {
    Node* p;
    if( (p = (Node*) malloc(sizeof(Node))) == NULL) {
        yyerror("out of memory");
    }
    return p;
}

Node* addConstant(int value) {
    Node* p = allocNode();

    p->type = T_CONSTANT;
    p->constant.value = value;
    return p;
}

Node* addIdentifier(char symIndex) {
    Node* p = allocNode();

    p->type = T_IDENTIFIER;
    p->identifier.symIndex = symIndex;
    return p;
}

Node* addOperation(int operator, int operandCount, ...) {
    Node* p = allocNode();

    p->type = T_OPERATION;
    p->operation.operator = operator;
    p->operation.operandCount = operandCount;
    va_list va;
    va_start(va, operandCount);
    for(int i = 0; i < operandCount; i++) {
        p->operation.operands[i] = va_arg(va, Node*);
    }
    va_end(va);

    return p;
}

int execute(Node* node) {
    switch(node->type) {
        case T_CONSTANT: return node->constant.value;
        case T_IDENTIFIER: return sym[node->identifier.symIndex];
        case T_OPERATION:
            OperationNode op = node->operation;
            switch(op.operator) {
                case ';':
                    execute(op.operands[0]);
                    return execute(op.operands[1]);

                case '!': return !execute(op.operands[0]);
                case UMINUS: return -execute(op.operands[0]);
                case '+': return execute(op.operands[0]) + execute(op.operands[1]);
                case '-': return execute(op.operands[0]) - execute(op.operands[1]);
                case '*': return execute(op.operands[0]) * execute(op.operands[1]);
                case '/': return execute(op.operands[0]) / execute(op.operands[1]);
                case '%': return execute(op.operands[0]) % execute(op.operands[1]);
                case '<': return execute(op.operands[0]) < execute(op.operands[1]);
                case '>': return execute(op.operands[0]) > execute(op.operands[1]);
                case EQ: return execute(op.operands[0]) == execute(op.operands[1]);
                case NE: return execute(op.operands[0]) != execute(op.operands[1]);
                case GE: return execute(op.operands[0]) >= execute(op.operands[1]);
                case LE: return execute(op.operands[0]) <= execute(op.operands[1]);
                case OR: return execute(op.operands[0]) || execute(op.operands[1]);
                case AND: return execute(op.operands[0]) && execute(op.operands[1]);

                case '=':
                    sym[op.operands[0]->identifier.symIndex] = execute(op.operands[1]);
                    return sym[op.operands[0]->identifier.symIndex];

                case IF:
                    if(execute(op.operands[0])) {
                        execute(op.operands[1]);
                    } else {
                        execute(op.operands[2]);
                    }
                    return 0;

                case WHILE:
                    while(execute(op.operands[0])) {
                        execute(op.operands[1]);
                    }

                case PRINT: 
                    printf("%d\n", execute(op.operands[0]));
                    return 0;

                default:
                    printf("Unknown Operation: %c\n", op.operator);
                    return 0;
            }
    }
    return 0;    
}
