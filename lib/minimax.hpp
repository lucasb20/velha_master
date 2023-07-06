typedef struct estado_terminal{
    char val;
    char *array;
} position;

typedef struct acoes_possiveis{
    unsigned int qtd;
    position *acoes;
}acts;

void _max(char*,position*);
void _min(char*,position*);
void copy_and_move(char*,char**,char,char);
void copy_match(char*,char**);
int search_max(acts*);
int search_min(acts*);
char do_machine_move(char*,bool);
void display(char*);