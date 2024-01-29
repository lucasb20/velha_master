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
        _ = Minimax.Max(new Node());

        var node1 = new Node();
        node1._array.Define_Match([1,2,1,2,1,2,2,1,0]);
        Assert(Minimax.Max(node1), 8);

        var node2 = new Node();
        node2._array.Define_Match([0,0,0,2,1,0,2,1,0]);
        Assert(Minimax.Max(node2), 0);
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

    public static void Assert(object obj1, object obj2){
        if(obj1.ToString() == obj2.ToString()){
            Console.WriteLine("Correct Assert.");
        }
        else{
            Console.WriteLine($"Invalid Assert. {obj1} != {obj2}");
        }
    }
}