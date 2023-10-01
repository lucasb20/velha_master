#include <iostream>
#include <vector>

#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe{
    public:
        int lance;
        std::vector <char> match;
    
        TicTacToe(): match(9,0),lance(0){}

        bool do_move(char casa){
            if(this->match[casa]==0){
                this->match[casa] = (!(this->lance%2))?1:2;
                this->lance++;
                return true;
            }
            else{
                return false;
            }
        }

        void display_match(){
            char casa = -1;
            for(int i = 0; i < 9; i++){
                switch(this->match[i]){
                    case 0:
                    casa = '-';
                    break;
                    case 1:
                    casa = 'X';
                    break;
                    case 2:
                    casa = 'O';
                    break;
                    default:
                    casa = '?';
                    break;
                }
                printf("%c",casa);
                if(i%3==2)std::cout << '\n';
            }
            std::cout << std::endl;
        }

        char getTurn(){
            return !(this->lance%2)?'X':'O';
        }

        int getTurn_num(){
            return !(this->lance%2)?1:2;
        }

        void define_match(char *array){
            for(int i = 0; i < 9; i++){
                this->match[i] = array[i];
            }
        }
};
#endif

void play_human_game(TicTacToe*);
char check_winner(std::vector<char>);