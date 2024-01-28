using velha_master.GameCreate;
using velha_master.Logic;

namespace velha_master;

class Program
{
    public static int Main(string[] args)
    {
        if(args.Length != 1){
            Console.WriteLine("Coloque o modo por argumento.");
            Console.WriteLine("0 -> Player vs Player");
            Console.WriteLine("1 -> Player vs Engine");
            Console.WriteLine("2 -> Engine vs Player");
            Console.WriteLine("3 -> Engine vs Engine");
            Console.WriteLine("4 -> Capivara vs Engine");
            Console.WriteLine("5 -> Engine vs Capivara");
            return 0;
        }
        if(args[0] == "test"){
            Tests.Tests.Test_All();
            return 0;
        }

        bool check = int.TryParse(args[0], out int choose);

        if(!check)return 1;

        var partida = new TicTacToe();

        if(choose == 0){
            HumanGame.Play_Human_Game(partida);
        }else{
            EngineGame.Play_vs_Engine(partida, choose);
        }

        return 0;
    }
}
