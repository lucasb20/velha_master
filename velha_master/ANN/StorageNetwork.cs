using System.Text.Json;
using Accord.Neuro;

namespace velha_master.ANN;

public static class StorageNetwork{
    public static void SaveNetwork(ActivationNetwork network, string fileName = "network.json")
    {
        string jsonString = JsonSerializer.Serialize(network);
        File.WriteAllText(fileName, jsonString);
    }

    public static ActivationNetwork LoadNetwork(string fileName = "network.json")
    {
        string jsonString = File.ReadAllText(fileName);
        var network = JsonSerializer.Deserialize<ActivationNetwork>(jsonString) ?? throw new Exception("Erro ao carregar a rede neural.");
        return network;
    }
}