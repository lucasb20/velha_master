namespace velha_master.Engine;

using Accord.Neuro;
using Accord.Neuro.Learning;
using velha_master.ANN;

public class ArtificialNeuralNetwork{
    private ActivationNetwork _network;
    
    public ArtificialNeuralNetwork(){
        _network = new ActivationNetwork(new BipolarSigmoidFunction(), 9, 15, 1);
        _network.Randomize();
    }

    public int Machine_Move(){
        return -1;
    }

    public void Training(List<Node> dataset){
        var teacher = new BackPropagationLearning(_network) { LearningRate = 0.01 };

        int i = 0;
        foreach (var node in dataset){
            var input = new double[] { node._array._match[0], node._array._match[1], node._array._match[2], node._array._match[3], node._array._match[4], node._array._match[5], node._array._match[6], node._array._match[7], node._array._match[8] };
            var output = new double[] { node._val };
            teacher.Run(input, output);
            Console.WriteLine($"partida {i}/{dataset.Count}");
            i++;
        }

        StorageNetwork.SaveNetwork(_network);
    }
}