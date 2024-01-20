namespace velha_master.Logic;

public enum Tttenum
{
    empty = 0,
    X = 1,
    O = 2
}

public enum Statesenum{
    runningMatch = 0,
    draw = -1,
    impossible = -2
}


public class TicTacToe{
        public int _lance;
        public int[] _match;
    
        public TicTacToe(){
            _lance = 0;
            _match = new int[9];
            for(int i = 0; i < 9; i++){
                _match[i] =  (int)Tttenum.empty;
            }
        }

        public bool DoMove(int casa){
            if(_match[casa]==(int)Tttenum.empty){
                _match[casa] = (int) ((_lance%2==0)?Tttenum.X:Tttenum.O);
                _lance++;
                return true;
            }
                return false;
        }

        public void DisplayMatch(){
            char casa;
            var i = 0;
            foreach(var space in _match){
                if(space == (int) Tttenum.empty){
                    casa = '-';
                }
                else if (space == (int) Tttenum.X){
                    casa = 'X';
                }
                else if (space == (int) Tttenum.O){
                    casa = 'O';
                }
                else{
                    casa = '?';
                }

                Console.Write(casa);
                if(i%3==2){
                    Console.Write("\n");
                }

                i++;
            }
        }

        public char GetTurn(){
            return _lance%2==0?'X':'O';
        }

        public int GetTurn_num(){
            return (int)(_lance%2==0?Tttenum.X:Tttenum.O);
        }

        public void Define_Match(char[] array){
            for(int i = 0; i < 9; i++){
                _match[i] = array[i];
            }
        }

        public static int Check_Winner(int[] partida){
            int winner = (int) Tttenum.empty;
            int qtd_winner = 0;
            for(int i = 0; i < 7; i+=3){
                if((partida[i] == partida[i+1]) && (partida[i+1] == partida[i+2]) && (partida[i] != (int) Tttenum.empty)){
                    winner = partida[i];
                    qtd_winner++;
                }
            }
            for(int i = 0; i < 3; i++){
                if((partida[i] == partida[i+3]) && (partida[i+3] == partida[i+6]) && (partida[i] != (int) Tttenum.empty)){
                    winner = partida[i];
                    qtd_winner++;
                }
            }
            if((partida[0] == partida[4]) && (partida[4] == partida[8]) && (partida[0] != (int) Tttenum.empty)){
                    winner = partida[0];
                    qtd_winner++;
                }
            if((partida[2] == partida[4]) && (partida[4] == partida[6]) && (partida[2] != (int) Tttenum.empty)){
                    winner = partida[2];
                    qtd_winner++;
                }

            if(qtd_winner > 1)return (int) Statesenum.impossible;

            if(winner != (int) Tttenum.empty)return winner;

            bool draw = true;
            for(int i = 0; i < 9; i++)if(partida[i]==(int) Tttenum.empty)draw=false;

            if(draw)return (int) Statesenum.draw;

            return (int) Statesenum.runningMatch;
        }

        public int Check_Winner(){
            return Check_Winner(_match);
        }
};