all: hello

hello: main.obj TicTacToe.obj minimax.obj
	g++ -o hello main.obj TicTacToe.obj minimax.obj

main.obj: main.cpp
	g++ -o main.obj -c main.cpp

TicTacToe.obj: TicTacToe.cpp
	g++ -o TicTacToe.obj -c TicTacToe.cpp

minimax.obj: minimax.cpp
	g++ -o minimax.obj -c minimax.cpp

clean:
	rm -f *.obj hello

remake: clean all