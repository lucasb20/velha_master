using velha_master.GameCreate;
using velha_master.Interfaces;

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

        if(choose == 0){
            PlayGame.Play_Match(new HumanPlayer(), new HumanPlayer());
        }
        else if(choose == 1){
            PlayGame.Play_Match(new HumanPlayer(), new MinimaxPlayer());
        }
        else if(choose == 2){
            PlayGame.Play_Match(new MinimaxPlayer(), new HumanPlayer());
        }
        else if(choose == 3){
            PlayGame.Play_Match(new MinimaxPlayer(), new MinimaxPlayer());
        }
        else if(choose == 4){
            PlayGame.Play_Match(new CapivaraPlayer(), new MinimaxPlayer());
        }
        else if(choose == 5){
            PlayGame.Play_Match(new MinimaxPlayer(), new CapivaraPlayer());
        }
        else{
            Console.WriteLine("Escolha um modo válido.");
        }

        return 0;
    }
}
