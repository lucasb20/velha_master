namespace velha_master.Engine;

using Accord.Neuro;
using Accord.Neuro.Learning;

public static class ArtificialNeuralNetwork{
    public static int Machine_Move(){
        return 0;
    }

    public static void Training(){
        var func = new BipolarSigmoidFunction();

        var network = new ActivationNetwork(func, 9, 15, 1);
        network.Randomize();

        var teacher = new BackPropagationLearning(network) { LearningRate = 0.01 };

        network.Save("minimax.ann");
    }
}