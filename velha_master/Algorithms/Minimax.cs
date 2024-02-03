using velha_master.Logic;

namespace velha_master.Engine;

public static class Minimax
{
    public static int Minimax_Tree(Node pos, bool Maximize){
        if(Check_First_Move(pos)){
            var random = new Random();
            int rand_num = random.Next(0, 9);
            return rand_num;
        }

        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        int best_val = Maximize?-2:2;
        int best_move = -1;
        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                Minimax_Tree(node, !Maximize);
                if(Maximize){
                    if(node._val > best_val){
                        best_val = node._val;
                        best_move = i;
                    }
                }
                else{
                    if(node._val < best_val){
                        best_val = node._val;
                        best_move = i;
                    }
                }
            }
        }

        pos.Define(best_val);
        return best_move;
    }

    public static int Machine_Move(TicTacToe pos){
        var partida = new Node();
        partida._array.Define_Match(pos._match);

        return Minimax_Tree(partida, pos.GetTurn_num() == (int) Tttenum.X);
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

    private static bool Check_First_Move(Node pos){
        foreach(var num in pos._array._match){
            if(num != (int) Tttenum.empty){
                return false;
            }
        }

        return true;
    }
}