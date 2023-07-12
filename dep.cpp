//Arquivo de depuração

#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"
#include "lib/nnue.hpp"

#define DEBUG

int main(int argc, char**argv){
    srand(time(NULL));

    char example[] = {1,2,0,0,1,0,0,0,2};
    //char example[] = {0,1,1,2,0,2,0,0,0};
    //char example[] = {2,1,1,0,1,0,0,2,2};
    //char example[] = {0,1,0,0,2,2,1,0,0};
    //char example[] = {1,2,1,0,0,0,2,0,0};
    //char example[] = {2->6->0->1->7->4->5->8->3}
    //char example[] = {1,1,2,1,2,0,0,2,1};

    display(example);

    printf("A engine diz %hhd.\n",do_machine_move(example));

    vector<vector<w_type>> w_1(qtd_neu,vector<w_type>(qtd_in));
    vector<vector<w_type>> w_2(qtd_out,vector<w_type>(qtd_neu));
    vector<w_type> b_1(qtd_neu);
    vector<w_type> b_2(qtd_out);
    vector<w_type> res(qtd_out);

    fill_random(w_1);
    fill_random(w_2);
    fill_random(b_1);
    fill_random(b_2);

    nnue_algorithm(example,w_1,w_2,b_1,b_2,res);

    impress_w(res);

    return 0;
}