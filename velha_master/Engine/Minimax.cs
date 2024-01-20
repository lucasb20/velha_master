using velha_master.Logic;

namespace velha_master.Engine;

public class ImpossibleMatchFoundException : Exception
{
    public ImpossibleMatchFoundException(Node pos){
        Console.WriteLine("JOGADA IMPOSSÍVEL REALIZADA.");
        pos.DisplayMatch();
    }
}

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
        _val = copy._val;
        _array.Define_Match(copy._array._match);
        DoMove(index);
    }

    public void Define(int val){
        _val = val;
    }

    public void DisplayMatch(){
        Console.WriteLine("val = {0} Eval_Pos = {1}", _val, Minimax.Evaluate_Pos(this));
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

        var children = new List<Node>();

        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                children.Add(node);
            }
        }

        foreach (var node in children)
        {
            _ = Min(node);
        }

        int pos_max = Search_Max(children);
        pos.Define(children[pos_max]._val);

        return FindDiffMove(pos, children[pos_max]);
    }

    public static int Min(Node pos){
        if(pos._array.Check_Winner() != (int) Statesenum.runningMatch){
            pos.Define(Evaluate_Pos(pos));
            return -1;
        }

        var children = new List<Node>();

        for(int i = 0; i < 9; i++){
            if(pos._array._match[i] == (int) Tttenum.empty){
                var node = new Node();
                node.Define(i, pos);
                children.Add(node);
            }
        }

        foreach (var node in children)
        {
            _ = Max(node);
        }

        int pos_min = Search_Min(children);
        pos.Define(children[pos_min]._val);

        return FindDiffMove(pos, children[pos_min]);
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
        else if(res == (int) Statesenum.impossible){
            throw new ImpossibleMatchFoundException(pos);
        }
        else{
            return 0;
        }
    }

    private static int Search_Max(List<Node> array){
        int max = -2;
        int i = 0;
        int pos = -1;
        foreach(var node in array){
            if(node._val > max){
                max = node._val;
                pos = i;
            }
            i++;
        }
        return pos;
    }

    private static int Search_Min(List<Node> array){
        int min = 2;
        int i = 0;
        int pos = -1;
        foreach(var node in array){
            if(node._val < min){
                min = node._val;
                pos = i;
            }
            i++;
        }
        return pos;
    }

    private static int FindDiffMove(Node a, Node b){
        for(int i = 0; i < 9; i++){
            if(a._array._match[i] != b._array._match[i]){
                return i;
            }
        }
        return -1;
    }
}