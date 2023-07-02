# Projeto Quiz

Projeto realizado em C++ utilizando conceitos da formação de Programação WEB IEFP, utilizado 100% C++.
Seguindo os requisitos solicitados no [projeto.](#situação)

## QuizVerse


<img src="./docs/quizverselogo.gif" alt="Quiz Verse logo" width="540" height="503" />


  Aplicação é um Quiz sobre conhecimentos gerais com uma variedade de temas. A cada partida
são 10 perguntas com múltiplas escolhas que valem 5 pontos a cada resposta correta. Temos
ainda a escolha da dificuldade para aqueles jogadores mais avançados. Faça o seu cadastro
e que comecem os jogos!

## Pré requisitos

- Permissão para ler, editar e gravar na pasta;
- C++ 17.

## Usabilidade

![Quiz Verse usage](./docs/quizverse_usage.gif)

## Situação

  Desenvolva uma aplicação que simule um Quiz. Este programa deve permitir aos
utilizadores fazer um registo simples com o nome de utilizador, email e password e terá
acesso a uma página onde constará os seus pontos acumulados no jogo. O Quiz deverá
englobar vários temas, com questões de escolha múltipla. O login do jogador, bem como
a sua pontuação devem ser guardados num ficheiro TXT (bloco de notas) e deverá ser
lido sempre que seja feito login.

## Visão Geral do Projeto

1. O Quiz deverá ter as seguintes características:
2. O utilizador tem a possibilidade de fazer signin e login;
3. A tela da conta deve mostrar as seguintes opções:
o Nome de utilizador;
o Pontuação;
o Iniciar jogo;
o Sair.
4. Quando o jogador iniciar o jogo deverão ser apresentados os temas das
perguntas;
5. Após escolha do tema devem ser apresentadas, à vez, 10 perguntas de
escolha múltipla com 4 opções de resposta;
6. Cada tema deve ter mais de 10 perguntas de escolha múltipla, no entanto,
cada vez que se jogar apenas serão apresentadas 10 perguntas;
7. O feedback da resposta deve ser imediato;
8. Cada resposta certa valerá um total de 5 pontos, que serão adicionados à
sua pontuação geral.
9. No final do Quiz, o programa retornará à tela da conta

## Características adicionais do Projeto (opcional)

Cada uma destas características adicionais implementadas, valerão mais pontos
à nota final do projeto:

1. Tempo limite de resposta
2. Eliminar conta
3. Reset de pontuação
4. Adicionar 3 níveis de dificuldade
5. Recuperação de Password
6. Tabela de líderes
