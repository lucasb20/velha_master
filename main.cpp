#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"

int main(int argc, char**argv){
    if(argc!=2){
        printf("Digite %s <choose>\n",*argv);
        printf("op:\n0 -> Player vs Player\n1 -> Player vs Engine\n2 -> Engine vs Player\n3 -> Engine vs Engine\n");
        exit(1);
    }
    int choose = atoi(*(argv+1));

/*     char example[] = {1,2,0,0,1,0,0,0,2};
    
    display(example);

    printf("A engine diz %hhd.\n",do_machine_move(example,true));
 */
    /* while (true)
    {
        partida.display_match();
        entry = do_machine_move(partida.match,true);
        printf("A engine diz %hhd.\n",entry);
        if(entry != -3)partida.do_move(entry);
        if(check_winner(partida.match)!=0)break;
        partida.display_match();
        do{
            std::cout << "Your move.\n";
            scanf("%hhd",&entry);
        }while(!partida.do_move(entry));
        if(check_winner(partida.match)!=0)break;
    } */
    

/* 
    switch(choose){
        case 0:
        play_human_game(&partida);
        break;
        default:
        play_vs_engine(&partida,choose);
        break;
    }
 */
    return 0;
}