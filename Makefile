CC = g++
CFLAGS = -c
OBJS = main.obj TicTacToe.obj minimax.obj
OBJS_debug = dep.obj TicTacToe.obj minimax.obj nnue.obj
OBJS_inter = interface.obj TicTacToe.obj minimax.obj interfaceFuncs.obj
EXE = hello

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

main.obj: main.cpp
	$(CC) -o main.obj $(CFLAGS) main.cpp

TicTacToe.obj: TicTacToe.cpp
	$(CC) -o TicTacToe.obj $(CFLAGS) TicTacToe.cpp

minimax.obj: minimax.cpp
	$(CC) -o minimax.obj $(CFLAGS) minimax.cpp

nnue.obj: nnue.cpp
	$(CC) -o nnue.obj $(CFLAGS) nnue.cpp

dep.obj: dep.cpp
	$(CC) -o dep.obj $(CFLAGS) dep.cpp

interface.obj: interface.cpp
	$(CC) -o interface.obj $(CFLAGS) interface.cpp

interfaceFuncs.obj: interfaceFuncs.cpp
	$(CC) -o interfaceFuncs.obj $(CFLAGS) interfaceFuncs.cpp

clean:
	rm -f *.obj $(EXE)

inter: $(OBJS_inter)
	$(CC) -o $(EXE) $(OBJS_inter) -lSDL2

debug: $(OBJS_debug)
	$(CC) -o $(EXE) $(OBJS_debug)

remake: clean all