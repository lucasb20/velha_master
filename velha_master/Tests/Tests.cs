using velha_master.Engine;
using velha_master.Logic;
using Accord.Neuro;
using Accord.Neuro.Learning;

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
        var match = new TicTacToe();
        _ = Minimax.Machine_Move(match);

        var match1 = new TicTacToe();
        match1.Define_Match([1,2,1,2,1,2,2,1,0]);
        Assert(Minimax.Machine_Move(match1), 8);

        var match2 = new TicTacToe();
        match2.Define_Match([0,0,0,2,1,0,2,1,0]);
        Assert(Minimax.Machine_Move(match2), 0);
    }

    public static void ANN(){
        var func = new BipolarSigmoidFunction();

        var network = new ActivationNetwork(func, 2, 15, 1);
        network.Randomize();

        var teacher = new BackPropagationLearning(network) { LearningRate = 0.01 };

        var train_x = new double[][]{
                [0, 0],
                [0, 1],
                [1, 0],
                [1, 1]
        };

        var train_y = new double[][]{
                [0],
                [1],
                [1],
                [0]
        };

        for (int i = 0; i < 1000000; i++)
        {
            teacher.RunEpoch(train_x, train_y);
            Console.WriteLine($"Epoch {i}");
        }

        var output = new List<double[]>();

        foreach(var input in train_x){
            output.Add(network.Compute(input));
        }


        foreach(var item in output){
            foreach(var value in item){
                Console.WriteLine($"{value} ");
            }
        }
    }

    public static void ANN2(){
        var func = new BipolarSigmoidFunction();

        var network = new ActivationNetwork(func, 9, 15, 1);
        network.Randomize();

        var teacher = new BackPropagationLearning(network) { LearningRate = 0.01 };


        Node.Load("minimax.stackdump", out double[][] train_x, out double[][] train_y);

        for (int i = 0; i < 2; i++)
        {
            teacher.RunEpoch(train_x, train_y);
            Console.WriteLine($"Epoch {i}");
        }

        network.Save("minimax.ann");
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