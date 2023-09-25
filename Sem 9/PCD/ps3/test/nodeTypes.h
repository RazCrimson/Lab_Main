typedef enum {
    T_CONSTANT,
    T_IDENTIFIER,
    T_OPERATION
} NodeTypeEnum;


typedef struct {
    int value;
} ConstantNode;

typedef struct {
    int symIndex;
} IdentifierNode;

typedef struct {
    int operator;
    int operandCount;
    struct nodeType* operands[5];
} OperationNode;

typedef struct nodeType {
    NodeTypeEnum type;

    union {
        ConstantNode constant;
        IdentifierNode identifier;
        OperationNode operation;
    };
} Node;

extern int sym[26];