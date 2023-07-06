#include "TicTacToe.hpp"

typedef struct estado_terminal{
    char val;
    char *array;
} position;

typedef struct acoes_possiveis{
    unsigned int qtd;
    position *acoes;
}acts;

char _max(char*,position*);
char _min(char*,position*);
void copy_and_move(char*,char**,char,char);
void copy_match(char*,char**);
int search_max(acts*);
int search_min(acts*);
char do_machine_move(char*,bool);
void display(char*);
void play_vs_engine(TicTacToe*,int);
char aval_pos(char*);
char check_diff(char*,char*);
void undo_move(char**,char);