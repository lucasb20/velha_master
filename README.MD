# Velha Master

**Descrição**

 Esse é um projeto de Jogo da Velha feito em C# com .NET. É possível fazer partidas normais entre pessoas, mas o foco é a interação com a engine chamada de Velha Master.

**Observações**

 Foi realizado um refactory de linguagem (C++ para C#) e de código de algoritmos.

 A interface foi removida porque SDL2 sozinho é um recurso fraco.

 O refactory do código teve como principal objetivo resolver o problema do código do Minimax absurdamente amarrado e de difícil manutenção.

**Recursos**

* Partida normal entre dois humanos
* Desafio de jogar contra o Velha Master, tanto de X quanto de O. 
* Ver partida de Engine vs Engine.

**Objetivos**

O objetivo do projeto é possibilitar uma interação com o algoritmo de busca competitiva, famoso Minimax. É uma I.A que busca as soluções das posições na força bruta.

**Instruções de instalação**

**Requisitos de sistema**

* .NET 8.0.0

**Instalação do aplicativo**

1. Entre na pasta do aplicativo
2. Execute o comando `dotnet run` para compilar e executar o projeto
3. Siga as instruções do terminal para começar

**Screenshots**

![Exemplo de partida no terminal](other/Screenshot1.png)