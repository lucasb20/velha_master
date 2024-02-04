using velha_master.Interfaces;
using velha_master.Logic;

namespace velha_master.GameCreate;

public class HumanPlayer : IPlayer
{
    public int Machine_Move(TicTacToe game)
    {
        Console.WriteLine("Digite o número da linha.");
        _ = int.TryParse(Console.ReadLine(), out int i);
        Console.WriteLine("Digite o número da coluna.");
        _ = int.TryParse(Console.ReadLine(), out int j);
        return (i-1)*3+(j-1);
    }
}