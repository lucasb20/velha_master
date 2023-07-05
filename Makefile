all: hello

hello: main.obj TicTacToe.obj
	g++ -o hello main.obj TicTacToe.obj

main.obj: main.cpp
	g++ -o main.obj -c main.cpp

TicTacToe.obj: TicTacToe.cpp
	g++ -o TicTacToe.obj -c TicTacToe.cpp

clean:
	rm -f *.obj hello

remake: clean all