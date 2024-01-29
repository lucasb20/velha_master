using velha_master.Logic;

namespace Tests;

public static class AjustedMinimax
{
    public static int Minimax(Node pos, bool Maximize = true){
        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        int val_min = 2;
        int val_max = -2;
        int best_move = -1;
        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                _ = Maximize?Minimax(node, false):Minimax(node);
                if(node._val > val_max){
                    val_max = node._val;
                    best_move = i;
                }
                if(node._val < val_min){
                    val_min = node._val;
                    best_move = i;
                }
            }
        }

        pos.Define(val_max);
        return best_move;
    }

    public static int Machine_Move(TicTacToe pos){
        var partida = new Node();
        partida._array.Define_Match(pos._match);

        return Minimax(partida, pos.GetTurn_num() == (int) Tttenum.X);
    }

    public static int Evaluate_Pos(Node pos){
        int res = pos._array.Check_Winner();
        if(res == (int) Tttenum.X){
            return 1;
        }
        else if(res == (int) Tttenum.O){
            return -1;
        }
        else{
            return 0;
        }
    }
}