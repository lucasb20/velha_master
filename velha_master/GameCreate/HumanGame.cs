using velha_master.Logic;

namespace velha_master.HumanGame;

public static class Game
{
    public static void Play_Human_Game(ref TicTacToe partida){
    int turn;
    int i, j;
    int move;
    
    while(partida.Check_Winner()==0){
        partida->display_match();
        turn = partida->getTurn();
        printf("Vez do %c (Formato -> linha,coluna)\n",turn);
        do{
            scanf("%d,%d",&i,&j);
            move = (i-1)*3+(j-1);
        }while(!(partida->do_move(move)));
    }

    switch(check_winner(partida->match)){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(check_winner(partida->match)%2)?'X':'O');
    }
}
}