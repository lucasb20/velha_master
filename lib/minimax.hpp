#include "TicTacToe.hpp"
#include <ctime>
#include <cstdlib>

typedef struct estado_terminal{
    int val;
    std::vector<char> array;
} position;

char _max(std::vector <char> pos,position*);
char _min(std::vector <char> pos,position*);
void copy_and_move(std::vector<char>,std::vector<char>&,char,char);
void copy_match(std::vector <char>,std::vector<char>&);
int search_max(std::vector<position>&);
int search_min(std::vector<position>&);
char do_machine_move(std::vector<char>);
void play_vs_engine(TicTacToe*,int);
char aval_pos(std::vector<char>);
char check_diff(std::vector<char>,std::vector<char>);
void undo_move(std::vector<char>&,char);
char calc_turn(std::vector<char>);