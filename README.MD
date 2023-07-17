# Velha Master

Um projeto de Jogo da Velha.

Você pode jogar Player vs Player, Player vs Maquina (X ou O) ou apenas ver uma partida entre os algoritmos.

O modo normal é no terminal, mas também há uma interface gráfica simples. Você seleciona o modo de jogo por linha de execução do mesmo jeito, mas a partida ocorre na tela e os movimentos são feitos com o clique do mouse.

A 'maquina' é um algoritmo que utiliza busca competitiva, o famoso minimax.

Depois de 3 dias seguidos de pura depuração tentando ajustar a precisão do algoritmo, eu consegui. Finalmente o algoritmo Minimax alcançou uma precisão muito boa.

Só não vou dizer que é uma precisão perfeita porque ele não difere posições minimamente melhores. Com 'posições melhores' quero dizer casos em que há mais chance do adversário errar. Se tiver como escolher entre duas posições empatadas, ele não vai se importar de saber que em uma o adversário tem mais opções de lances ruins e em outra só leva direto ao empate, ele escolhe qualquer uma delas.

Tentei criar uma versão desse algoritmo em redes neurais que aprenda a jogar treinando com o minimax. Infelizmente não sei bem como continuar isso, e vai ficar um bom tempo sem resultados.