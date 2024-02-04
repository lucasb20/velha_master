using velha_master.Engine;
using velha_master.Logic;

namespace velha_master.Interfaces;

public class MinimaxPlayer : IPlayer{
    public int Machine_Move(TicTacToe game){
        return Minimax.Machine_Move(game);
    }
}