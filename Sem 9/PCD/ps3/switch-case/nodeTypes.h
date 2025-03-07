typedef enum {
    T_CONSTANT,
    T_IDENTIFIER,
    T_OPERATION
} nodeEnum;

typedef struct {
    int value;
} conNodeType;

typedef struct {
    int i;
} idNodeType;

typedef struct {
    int oper;
    int nops;
    struct nodeTypeTag* op[];
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;
    union {
        conNodeType con;
        idNodeType id;
        oprNodeType opr;
    };
} nodeType;

extern int sym[26];