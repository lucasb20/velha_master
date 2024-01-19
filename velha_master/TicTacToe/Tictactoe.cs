namespace velha_master.TicTacToe;

enum tttenum
{
    empty = 0,
    X = 1,
    O = 2
}

public class TicTacToe{
        public int _lance;
        public char[] _match;
    
        public TicTacToe(){
            this._lance = 0;
            this._match = new char[9];
            for(int i = 0; i < 9; i++){
                this._match[i] = tttenum.empty;
            }
        }

        public void do_move(char casa){
            if(this._match[casa]==tttenum.empty){
                this._match[casa] = (!(this->_lance%2))?tttenum.X:tttenum.O;
                this->_lance++;
                return true;
            }
            else{
                return new Exception("Casa já ocupada");
            }
        }

        public void display_match(){
            char casa = -1;
            for(int i = 0; i < 9; i++){
                switch(this->_match[i]){
                    case tttenum.empty:
                    casa = '-';
                    break;
                    case tttenum.X:
                    casa = 'X';
                    break;
                    case tttenum.O:
                    casa = 'O';
                    break;
                    default:
                    casa = '?';
                    break;
                }
                Console.log(casa);
                if(i%3==2){
                    Console.log("\n");
                }
            }
        }

        public char getTurn(){
            return !(this->_lance%2)?'X':'O';
        }

        public int getTurn_num(){
            return !(this->_lance%2)?tttenum.X:tttenum.O;
        }

        public void define_match(char[] array){
            for(int i = 0; i < 9; i++){
                this->_match[i] = array[i];
            }
        }
};