using velha_master.Logic;

namespace velha_master.HumanGame;

public static class Game
{
    public static void Play_Human_Game(ref TicTacToe partida){
        char turn;
        int i, j;
        int move;

        while(partida.Check_Winner()==(int) Statesenum.runningMatch){
            partida.DisplayMatch();
            turn = partida.GetTurn();
            Console.WriteLine($"Vez do {turn}");
            do{
                Console.WriteLine("Digite o número da linha.");
                i = int.Parse(Console.ReadLine());
                Console.WriteLine("Digite o número da coluna.");
                j = int.Parse(Console.ReadLine());
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