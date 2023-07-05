#include <iostream>

class TicTacToe{
    private:
        unsigned char lance;
        char match[9];
    public:
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

        char check_winner(){
            char winner = 0;
            char qtd_winner = 0;
            for(int i = 0; i < 7; i+=3){
                if((this->match[i] == this->match[i+1]) && (this->match[i+1] == this->match[i+2]) && (this->match[i] != 0)){
                    winner = this->match[i];
                    qtd_winner++;
                }
            }
            for(int i = 0; i < 3; i++){
                if((this->match[i] == this->match[i+3]) && (this->match[i+3] == this->match[i+6]) && (this->match[i] != 0)){
                    winner = this->match[i];
                    qtd_winner++;
                }
            }
            if((this->match[0] == this->match[4]) && (this->match[4] == this->match[8]) && (this->match[0] != 0)){
                    winner = this->match[0];
                    qtd_winner++;
                }
            if((this->match[2] == this->match[4]) && (this->match[4] == this->match[6]) && (this->match[2] != 0)){
                    winner = this->match[2];
                    qtd_winner++;
                }

            if(qtd_winner > 1)return -2;

            if(winner != 0)return winner;

            bool draw = true;
            for(char &i : this->match)if(i==0)draw=false;

            if(draw)return -1;

            return 0;
        }

        char getTurn(){
            return !(this->lance%2)?'x':'o';
        }
};

void play_human_game(TicTacToe*);