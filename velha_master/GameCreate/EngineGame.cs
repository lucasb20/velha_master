using velha_master.Engine;
using velha_master.Logic;

namespace velha_master.GameCreate;

public static class EngineGame
{
    public static void Play_vs_Engine(TicTacToe partida, int option){
        if(option == 1){
            while(true){
                Console.WriteLine("Vez do {0}.", partida.GetTurn());
                _ = int.TryParse(Console.ReadLine(), out int move);
                partida.DoMove(move);
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                partida.DoMove(Minimax.Machine_Move(partida));
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
            }
        }
        else if(option == 2){
            while(true){
                partida.DoMove(Minimax.Machine_Move(partida));
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                Console.WriteLine("Vez do {0}.", partida.GetTurn());
                _ = int.TryParse(Console.ReadLine(), out int move);
                partida.DoMove(move);
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
            }
        }
        else if(option == 3){
            while(true){
                partida.DoMove(Minimax.Machine_Move(partida));
                Console.WriteLine("Vez do X.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                partida.DoMove(Minimax.Machine_Move(partida));
                Console.WriteLine("Vez do O.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
            }
        }
        else if(option == 4){
            while(true){
                partida.DoMove(Capivara.Machine_Move(partida));
                Console.WriteLine("Vez do X.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                partida.DoMove(Minimax.Machine_Move(partida));
                Console.WriteLine("Vez do O.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
            }
        }
        else if(option == 5){
            while(true){
                partida.DoMove(Minimax.Machine_Move(partida));
                Console.WriteLine("Vez do X.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
                partida.DoMove(Capivara.Machine_Move(partida));
                Console.WriteLine("Vez do O.");
                partida.DisplayMatch();
                if(partida.Check_Winner() != (int) Statesenum.runningMatch)break;
            }
        }
        else{
            Console.WriteLine("Opção inválida.");
        }

        if(partida.Check_Winner() == (int) Statesenum.draw){
            Console.WriteLine("Draw.");
        }
        else{
            Console.WriteLine("O vencedor foi {0}.", (Tttenum) partida.Check_Winner());
        }
    }
}