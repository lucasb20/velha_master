using velha_master.Logic;

namespace velha_master.Tests;

public static class Tests
{   
    public static void Test_All(){
        Criar_Partida();
    }
    public static void Criar_Partida(){
        var my_match = new TicTacToe();
        Console.WriteLine($"my_match = {my_match._match}");
    }
}