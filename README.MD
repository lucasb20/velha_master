# Velha Master

Um projeto de Jogo da Velha, é possível tanto jogos com humanos como com maquinas.

Há um algoritmo que utiliza busca competitiva, o famoso minimax.

Dá para jogar tanto de X como de O contra o algoritmo.

Depois de 3 dias seguidos de pura depuração tentando ajustar a precisão do algoritmo, eu consegui. Agora finalmente alcançou uma precisão muito boa.

Só não vou dizer que é uma precisão perfeita porque ele não difere posições minimamente melhores. Com 'posições melhores' quero dizer casos em que há mais chance do adversário errar. Se tiver como escolher entre duas posições empatadas, ele não vai se importar de saber que em uma o adversário tem mais opções de lances ruins e em outra só leva direto ao empate, ele escolhe qualquer uma delas.