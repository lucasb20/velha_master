
using velha_master.Logic;

public class Node
{
    public int _val;
    public TicTacToe _array;

    public Node(){
        _val = 0;
        _array = new TicTacToe();
    }

    public void Define(int index, Node copy){
        _array.Define_Match(copy._array._match);
        _array.DoMove(index);
    }

    public void Define(int val){
        _val = val;
    }
}
