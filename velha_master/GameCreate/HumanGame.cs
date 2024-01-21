using velha_master.Logic;

namespace velha_master.HumanGame;

public static class Game
{
    public static void Play_Human_Game(TicTacToe partida){
        char turn;
        int move;

        while(partida.Check_Winner()==(int) Statesenum.runningMatch){
            partida.DisplayMatch();
            turn = partida.GetTurn();
            Console.WriteLine($"Vez do {turn}");
            do{
                Console.WriteLine("Digite o número da linha.");
                _ = int.TryParse(Console.ReadLine(), out int i);
                Console.WriteLine("Digite o número da coluna.");
                _ = int.TryParse(Console.ReadLine(), out int j);
                move = (i-1)*3+(j-1);
            }while(!partida.DoMove(move));
        }

        if(partida.Check_Winner() == (int) Statesenum.draw){
            Console.WriteLine("Draw.");
        }
        else{
                char winner = partida.Check_Winner() == (int) Tttenum.X?'X':'O';
                Console.WriteLine($"O vencedor foi {winner}.");
        }
    }
}