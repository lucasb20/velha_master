using velha_master.Interfaces;
using velha_master.Logic;

namespace velha_master.GameCreate;

public static class PlayGame{
    public static void Play_Match(IPlayer player1, IPlayer player2){
        var game = new TicTacToe();

        char turn;

        while(game.Check_Winner()==(int) Statesenum.runningMatch){
            game.DisplayMatch();
            turn = game.GetTurn();
            Console.WriteLine($"Vez do {turn}");
            if(turn == 'X'){
                _ = player1.Machine_Move(game);
            }
            else{
                _ = player2.Machine_Move(game);
            }
        }

        if(game.Check_Winner() == (int) Statesenum.draw){
            Console.WriteLine("Draw.");
        }
        else{
                char winner = game.Check_Winner() == (int) Tttenum.X?'X':'O';
                Console.WriteLine($"O vencedor foi {winner}.");
        }
    }

    internal static void Play_Match(object value1, object value2)
    {
        throw new NotImplementedException();
    }
}