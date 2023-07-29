CC = g++
CFLAGS = -c
LFLAGS = -lSDL2
SRCS = main.cpp TicTacToe.cpp minimax.cpp
OBJS = $(SRCS:.cpp=.obj)
OBJS_inter = interface.obj TicTacToe.obj minimax.obj interfaceFuncs.obj
EXE = hello

# Regra padrão para gerar todos os executáveis
all: $(EXE)

# Regra para gerar o executável principal
$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

# Regra padrão para gerar um arquivo .obj a partir de um arquivo .cpp
%.obj: %.cpp
	$(CC) -o $@ $(CFLAGS) $<

# Regra para limpar os arquivos gerados
clean:
	rm -f *.obj $(EXE)

# Regra para gerar o executável da interface
inter: $(OBJS_inter)
	$(CC) -o $(EXE) $(OBJS_inter) $(LFLAGS)