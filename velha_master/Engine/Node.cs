namespace velha_master.Engine;
using velha_master.Logic;

public class Node
{
    public int _val;
    public TicTacToe _array;

    public Node(){
        _val = 0;
        _array = new TicTacToe();
    }

    public void Define(int index, Node copy){
        _array.Define_Match(copy._array._match);
        _array.DoMove(index);
    }

    public void Define(int val){
        _val = val;
    }

    public static void Load(string path, out double[][] input, out double[][] output)
    {
        var reader = new StreamReader(path);

        string? linha;
        int count = 0;
        while (reader.ReadLine() != null)
        {
            count++;
        }

        input = new double[count][];
        output = new double[count][];

        for (int i = 0; i < count; i++)
        {
            if((linha = reader.ReadLine()) == null){
                break;
            }
            string[] valores = linha.Split(' ');

            double[] inputDouble = new double[9];
            double[] outputDouble = new double[1];

            for (int j = 0; j < 9; j++)
            {
                inputDouble[j] = double.Parse(valores[j]);
            }

            outputDouble[0] = double.Parse(valores[9]);

            input[i] = inputDouble;
            output[i] = outputDouble;
        }

        reader.Close();
    }
}
