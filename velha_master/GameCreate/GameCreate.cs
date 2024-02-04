using velha_master.Interfaces;
using velha_master.Logic;

namespace velha_master.GameCreate;

public static class PlayGame{
    public static void Play_Match(IPlayer player1, IPlayer player2){
        var game = new TicTacToe();

        int move;
        char turn;

        while(game.Check_Winner()==(int) Statesenum.runningMatch){
            game.DisplayMatch();
            turn = game.GetTurn();
            Console.WriteLine($"Vez do {turn}");
            do{
                if(turn == 'X'){
                move = player1.Machine_Move(game);
                }
                else{
                move = player2.Machine_Move(game);
                }
            }while(!game.DoMove(move));
        }

        game.DisplayMatch();
        if(game.Check_Winner() == (int) Statesenum.draw){
            Console.WriteLine("Draw.");
        }
        else{
            char winner = game.Check_Winner() == (int) Tttenum.X?'X':'O';
            Console.WriteLine($"O vencedor foi {winner}.");
        }
    }
}