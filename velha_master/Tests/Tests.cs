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
            Assert(true, true);
        }
        Assert(my_match.GetTurn_num(), 1);
    }
    public static void Minimax_Debug(){
        _ = Minimax.Max(new Node());

        var node1 = new Node();
        node1._array.Define_Match([1,2,1,2,1,2,2,1,0]);
        Assert(Minimax.Max(node1), 8);

        var node2 = new Node();
        node2._array.Define_Match([0,0,0,2,1,0,2,1,0]);
        Assert(Minimax.Max(node2), 0);
    }

    public static void Assert(object obj1, object obj2){
        if(obj1.ToString() == obj2.ToString()){
            Console.WriteLine("Correct Assert.");
        }
        else{
            Console.WriteLine($"Invalid Assert. {obj1} != {obj2}");
        }
    }
}