#include <iostream>

class TicTacToe{
    public:
        unsigned char lance;
        char match[9];
    
        TicTacToe(){
            for(char &i : this->match){
                i = 0;
            }
            this->lance = 0;
        }

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
            char casa=-1;
            for(int i = 0; i < 9; i++){
                switch(this->match[i]){
                    case 0:
                    casa = '-';
                    break;
                    case 1:
                    casa = 'x';
                    break;
                    case 2:
                    casa = 'o';
                    break;
                    default:
                    casa = '?';
                    break;
                }
                printf("%c",casa);
                if(i%3==2)std::cout << '\n';
            }
        }

        char getTurn(){
            return !(this->lance%2)?'x':'o';
        }

        char getTurn_num(){
            return !(this->lance%2)?1:2;
        }

        void define_match(char *array){
            for(int i = 0; i < 9; i++){
                this->match[i] = array[i];
            }
        }
};

void play_human_game(TicTacToe*);
char check_winner(char*);