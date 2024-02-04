using velha_master.Engine;
using velha_master.Logic;

namespace velha_master.Interfaces;

public class CapivaraPlayer : IPlayer
{
    public int Machine_Move(TicTacToe game)
    {
        return Capivara.Machine_Move(game);;
    }
}