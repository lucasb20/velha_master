using velha_master.Logic;

namespace velha_master.MachineGame;

public static class Game
{
    public static void Play_vs_Engine(TicTacToe partida, int option){
        char turn;
        int move;

        if(option == 1){
            while(true){
                turn = partida.GetTurn();
                Console.WriteLine("Vez do {0}.", turn);
                Console.WriteLine("Digite o número da linha.");
                _ = int.TryParse(Console.ReadLine(), out move);
                partida.DoMove(i);
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                move = do_machine_move(partida->match);
                if(move != -3)partida->do_move(move);
                partida->display_match();
                if(check_winner(partida->match) != 0)break;
            }
        }
        else if(option == 2){
            while(true){
                move = do_machine_move(partida->match);
                if(move != -3)partida->do_move(move);
                partida->display_match();
                if(check_winner(partida->match) != 0)break;
                turn = partida->getTurn();
                printf("Vez do %c (Formato -> posição da casa)\n",turn);
                do{
                    scanf("%d",&move);
                }while(!(partida->do_move(move)));
                partida->display_match();
                if(check_winner(partida->match) != 0)break;
            }
        }
        else{
            while(true){
                move = do_machine_move(partida->match);
                if(move != -3)partida->do_move(move);
                printf("Vez do X:\n");
                partida->display_match();
                if(check_winner(partida->match) != 0)break;
                move = do_machine_move(partida->match);
                if(move != -3)partida->do_move(move);
                printf("Vez do O:\n");
                partida->display_match();
                if(check_winner(partida->match) != 0)break;
            }
        }

        switch(check_winner(partida->match)){
            case -1:
            std::cout << "Draw.\n";
            break;
            default:
            printf("O vencedor foi %c.\n",(check_winner(partida->match)%2)?'X':'O');
        }
    }

    char do_machine_move(std::vector<char> pos){
    position *aux = new position;
    aux->array.assign(9,0);
    char res = -3;

    char option = calc_turn(pos)-1;

    if(!option){
        _max(pos,aux);
    }
    else{
        _min(pos,aux);
    }

    res = check_diff(aux->array,pos);
    delete aux;
    return res;
}
}