using velha_master.Logic;

namespace velha_master.Engine;

public class Node
{
    public int _val;
    public TicTacToe _array;

    public Node(){
        _val = 0;
        _array = new TicTacToe();
    }

    public void Define(int val, int index){
        _val = val;
        DoMove(index);
    }

    public void Define(int index, Node copy){
        Define(copy._val);
        _array.Define_Match(copy._array._match);
        DoMove(index);
    }

    public void Define(int val){
        if(_val == 0){
            _val = val;
        }
    }

    public void DisplayMatch(){
        Console.WriteLine("val = {0}", _val);
        _array.DisplayMatch();
    }

    public void DoMove(int casa){
        bool check = _array.DoMove(casa);
        if(!check){
            throw new Exception("Unexpected Move.");
        }
    }
}

public static class Minimax
{
    public static int Max(Node pos){
        if(Check_First_Move(pos)){
            var random = new Random();
            int rand_num = random.Next(0, 9);
            return rand_num;
        }

        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        int val_max = -2;
        int best_move = -1;
        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                _ = Min(node);
                if(node._val > val_max){
                    val_max = node._val;
                    best_move = i;
                }
            }
        }

        pos.Define(val_max);
        return best_move;
    }

    public static int Min(Node pos){
        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        int val_min = 2;
        int best_move = -1;
        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                _ = Max(node);
                if(node._val < val_min){
                    val_min = node._val;
                    best_move = i;
                }
            }
        }

        pos.Define(val_min);
        return best_move;
    }

    private static bool Check_First_Move(Node pos){
        foreach(var num in pos._array._match){
            if(num != (int) Tttenum.empty){
                return false;
            }
        }

        return true;
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