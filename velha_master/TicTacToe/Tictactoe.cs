namespace velha_master.Logic;

public enum Tttenum
{
    empty = 0,
    X = 1,
    O = 2
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

        public void DoMove(char casa){
            if(_match[casa]==(int)Tttenum.empty){
                _match[casa] = (int) ((_lance%2==0)?Tttenum.X:Tttenum.O);
                _lance++;
                return;
            }
                throw new Exception("Casa já ocupada");
        }

        public void DisplayMatch(){
            int casa;
            for(int i = 0; i < 9; i++){
                casa = _match[i] switch
                {
                    (int) Tttenum.empty => '-',
                    (int) Tttenum.X => 'X',
                    (int) Tttenum.O => 'O',
                    _ => '?',
                };
                Console.Write(casa);
                    if(i%3==2){
                        Console.Write("\n");
                }
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
};