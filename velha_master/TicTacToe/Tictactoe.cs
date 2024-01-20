namespace velha_master.Logic;

public enum Tttenum
{
    empty = 0,
    X = 1,
    O = 2
}

public enum Statesenum{
    runningMatch = 0,
    draw = -1
}


public class TicTacToe{
        public int[] _match;
    
        public TicTacToe(){
            _match = new int[9];
            for(int i = 0; i < 9; i++){
                _match[i] =  (int)Tttenum.empty;
            }
        }

        public bool DoMove(int casa){
            if(_match[casa]==(int)Tttenum.empty){
                _match[casa] = GetTurn_num();
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
            return GetTurn_num()%2==(int)Tttenum.X?'X':'O';
        }

        public int GetTurn_num(){
            int count = 0;
            for(int i = 0; i < 9; i++){
                if(_match[i] != (int) Tttenum.empty)count++;
            }
            return (int)(count%2==0?Tttenum.X:Tttenum.O);
        }

        public void Define_Match(int[] array){
            for(int i = 0; i < 9; i++){
                _match[i] = array[i];
            }
        }

        public static int Check_Winner(int[] partida){
            int winner = (int) Tttenum.empty;
            for(int i = 0; i < 7; i+=3){
                if((partida[i] == partida[i+1]) && (partida[i+1] == partida[i+2]) && (partida[i] != (int) Tttenum.empty)){
                    winner = partida[i];
                }
            }
            for(int i = 0; i < 3; i++){
                if((partida[i] == partida[i+3]) && (partida[i+3] == partida[i+6]) && (partida[i] != (int) Tttenum.empty)){
                    winner = partida[i];
                }
            }
            if((partida[0] == partida[4]) && (partida[4] == partida[8]) && (partida[0] != (int) Tttenum.empty)){
                    winner = partida[0];
                }
            if((partida[2] == partida[4]) && (partida[4] == partida[6]) && (partida[2] != (int) Tttenum.empty)){
                    winner = partida[2];
                }


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