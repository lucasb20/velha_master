using velha_master.HumanGame;
using velha_master.Logic;

namespace velha_master;

class Program
{
    public static int Main(string[] args)
    {
        if(args.Length != 1){
            Console.WriteLine("Coloque o modo por argumento. Formato: dotnet run <op>");
            Console.WriteLine("0 -> Player vs Player");
            return 0;
        }
        if(args[0] == "test"){
            Tests.Tests.Test_All();
            return 1;
        }

        bool check = int.TryParse(args[0], out int choose);

        if(!check)return 1;

        var partida = new TicTacToe();

        if(choose == 0){
            Game.Play_Human_Game(ref partida);
        }

        return 0;
    }
}
