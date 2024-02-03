using velha_master.Logic;

namespace velha_master.Engine;

public static class PosIterator
{
    public static int Minimax_Tree(Node pos, bool Maximize, List<Node> matchs){
        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Minimax.Evaluate_Pos(pos));
            matchs.Add(pos);
            return -1;
        }

        int best_val = Maximize?-2:2;
        int best_move = -1;
        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                Minimax_Tree(node, !Maximize, matchs);
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
        matchs.Add(pos);
        return best_move;
    }
}