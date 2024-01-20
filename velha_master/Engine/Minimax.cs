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
        _array.DoMove(index);
    }

    public void Define(int val){
        _val = val;
    }

    public void Define(int val, TicTacToe pos){
        _val = val;
        _array.Define_Match(pos._match);
    }
}

public static class Minimax
{
    public static int Max(ref Node pos){
        if(Check_First_Move(pos)){
            var random = new Random();
            int rand_num = random.Next(0, 9);
            pos.Define(0, rand_num);
            return rand_num;
        }

        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            if(pos._array.Check_Winner() == (int) Statesenum.impossible){
                Console.WriteLine("ERRO");
                pos._array.DisplayMatch();
                throw new Exception("Posição impossível identificada.");
            }

            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        var children = new List<Node>();

        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(0, i);
                children.Add(node);
            }
        }

        return -1;
    }

    public static int Min(ref Node res){
        return 0;
    }

    private static bool Check_First_Move(Node pos){
        foreach(var num in pos._array._match){
            if(num != (int) Tttenum.empty){
                return false;
            }
        }

        return true;
    }

    private static int Evaluate_Pos(Node pos){
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