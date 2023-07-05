typedef struct estado_terminal{
    char val;
    char *array;
} position;

typedef struct acoes_possiveis{
    unsigned int qtd;
    position *acoes;
}acts;

position _max(char*);
position _min(char*);
void copy_and_move(char*,char*,char,char);
void copy_match(char*,char*);
int search_max(acts*);
int search_min(acts*);