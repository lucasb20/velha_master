using velha_master.Logic;

namespace velha_master.Engine;

public static class Capivara{
    public static int Machine_Move(TicTacToe t){
        var moves = new List<int>();
        for(int i = 0; i < 9; i++){
            if(t._match[i] == (int) Tttenum.empty){
                moves.Add(i);
            }
        }

        var move = moves[new Random().Next(0, moves.Count)];
        return move;
    }
}