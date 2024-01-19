using velha_master.Logic;

namespace velha_master.Tests;

public static class Tests
{   
    public static void Test_All(){
        Criar_Partida();
    }
    public static void Criar_Partida(){
        var my_match = new TicTacToe();
        my_match.DoMove(2);
        my_match.DoMove(5);
        try
        {
            my_match.DoMove(5);
        }
        catch (Exception)
        {
            Console.WriteLine("Tudo certo por aqui.");
        }
        my_match.DisplayMatch();
        Console.WriteLine("Lance: {0} {1}", my_match.GetTurn_num(), my_match.GetTurn());
    }
}