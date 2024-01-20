using velha_master.Engine;
using velha_master.Logic;

namespace velha_master.Tests;

public static class Tests
{   
    public static void Test_All(){
        Criar_Partida();
        Minimax_Debug();
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
    public static void Minimax_Debug(){
        var node1 = new Node();
        var move_random = Minimax.Max(node1);
        Console.WriteLine($"Move Random: {move_random}.");

        var node2 = new Node();
        node2._array.Define_Match([1,2,1,2,1,2,2,1,0]);
        node2.DisplayMatch();
        var move_mate_X = Minimax.Max(node2);
        //Console.WriteLine($"Move: {move_mate_X}.");
    }
}