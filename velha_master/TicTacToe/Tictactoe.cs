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

        public int Check_Winner(){
            for(int i = 0; i < 7; i+=3){
                if((_match[i] == _match[i+1]) && (_match[i+1] == _match[i+2]) && (_match[i] != (int) Tttenum.empty)){
                    return _match[i];
                }
            }
            for(int i = 0; i < 3; i++){
                if((_match[i] == _match[i+3]) && (_match[i+3] == _match[i+6]) && (_match[i] != (int) Tttenum.empty)){
                    return _match[i];
                }
            }
            if((_match[0] == _match[4]) && (_match[4] == _match[8]) && (_match[0] != (int) Tttenum.empty)){
                    return _match[0];
                }
            if((_match[2] == _match[4]) && (_match[4] == _match[6]) && (_match[2] != (int) Tttenum.empty)){
                    return _match[2];
                }

            for(int i = 0; i < 9; i++){
                if(_match[i]==(int) Tttenum.empty){
                    return (int) Statesenum.runningMatch;
                }
            }

            return (int) Statesenum.draw;
        }
};