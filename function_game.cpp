#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include "function_utils.cpp"
#include "function_login.cpp"
#include "function_database.cpp"

#ifndef FUNCTION_GAME_H
#define FUNCTION_GAME_H

using namespace std;

bool compararPontos(const Usuario& usuario1, const Usuario& usuario2) {
    // Comparar pontos
    return usuario1.pontos > usuario2.pontos;}

int escolherTema(int &opcaoTema, int &opcaoDificuldade) {
    // Abre menu de temas e dificuldades e retorna string com as informações    

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Escolha o Tema - QuizVerse - ¦ - |" << resetCor() << endl;
    cout << "" << endl;
    cout << "1 > Geografia e Cultura" << endl;
    cout << "2 > Fisica e Matemática" << endl;
    cout << "3 > Química e Biologia" << endl;
    cout << "4 > Voltar" << endl;
    cout << ">>> ";
    cin >> opcaoTema;

    switch (opcaoTema) {
        case 1:
            // 1 > Tema Geografia e Cultura
            limparTela();
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ -  Geografia e Cultura - QuizVerse - ¦ - |" << resetCor() << endl;
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Nível de Dificuldade - QuizVerse - ¦ - |" << resetCor() << endl;
            cout << "" << endl;
            cout << "1 > Fácil" << endl;
            cout << "2 > Médio" << endl;
            cout << "3 > Difícil" << endl;
            cout << "4 > Voltar" << endl;
            cout << ">>> ";
            cin >> opcaoDificuldade;
            return 0;
            break;
            
        case 2:
            // 2 > Tema Fisica e Matemática
            limparTela();
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ -       Fisica e Matemática        - ¦ - |" << resetCor() << endl;
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Nível de Dificuldade - QuizVerse - ¦ - |" << resetCor() << endl;
            cout << "" << endl;
            cout << "1 > Fácil" << endl;
            cout << "2 > Médio" << endl;
            cout << "3 > Difícil" << endl;
            cout << "4 > Voltar" << endl;
            cout << ">>> ";
            cin >> opcaoDificuldade;
            return 0;
            break;

        case 3:
            // 3 > Tema Química e Biologia
            limparTela();
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ -       Química e Biologia         - ¦ - |" << resetCor() << endl;
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Nível de Dificuldade - QuizVerse - ¦ - |" << resetCor() << endl;
            cout << "" << endl;
            cout << "1 > Fácil" << endl;
            cout << "2 > Médio" << endl;
            cout << "3 > Difícil" << endl;
            cout << "4 > Voltar" << endl;
            cout << ">>> ";
            cin >> opcaoDificuldade;
            return 0;
            break;

        case 4:
            // Voltar
            return 1;
            break;

        default: cout << "A " << opcaoTema << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
    }
    return 1;    
}

void ranking(){
    // Acessa banco de dados e retorna lista de pontuacao
    int contador = 1;

    vector<Usuario> _ranking = databaseUsuarios();

    sort(_ranking.begin(), _ranking.end(), compararPontos);

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Ranking - QuizVerse - ¦ - |" << resetCor() << endl;
    cout << corLetra("ciano") << "------------------------------------" << endl;     
    cout << "| # | Nome              | Pontos   |" << endl;
    cout << "------------------------------------" << endl;

    for (const auto& usuario : _ranking) {                                    
        cout << " " << contador << "º  " << usuario.nomeCompleto;
        size_t tamanhoString = usuario.nomeCompleto.size();
        cout << calcularEspaco(tamanhoString);
        cout << " " << usuario.pontos << endl;
        contador ++;            
    }

    cout << "------------------------------------" << resetCor() << endl;
    cout << "" << endl;
    
}

int jogar(int opcaoTema, int opcaoDificuldade, string userEmail) {
    // Recebe as informações de escolha de tema e dificuldade, email e inicia leitura de arquivo de perguntas

    string _path; //recebe o path de acordo com as informações que vem da variavel opcaoTema opcaoDificuldade
    //Perguntas questao; //instacia do struct

    switch (opcaoTema) {
        case 1: // 1 > Tema Geografia e Cultura
            if (opcaoDificuldade == 1){_path = "1_geografia_1_faceis.txt";}
            else if (opcaoDificuldade == 2){_path = "1_geografia_2_normais.txt";}
            else if (opcaoDificuldade == 3){_path = "1_geografia_3_dificeis.txt";}
            break;

        case 2: // 2 > Tema Fisica e Matemática
            if (opcaoDificuldade == 1){_path = "2_matematica_1_faceis.txt";}
            else if (opcaoDificuldade == 2){_path = "2_matematica_2_normais.txt";}
            else if (opcaoDificuldade == 3){_path = "2_matematica_3_dificeis.txt";}
            break;


        case 3: // 3 > Tema Química e Biologia
            if (opcaoDificuldade == 1){_path = "3_quimica_1_faceis.txt";}
            else if (opcaoDificuldade == 2){_path = "3_quimica_2_normais.txt";}
            else if (opcaoDificuldade == 3){_path = "3_quimica_3_dificeis.txt";}
            break;
        
        default:
            break;
    }

    int pontosUser = 0; //Pontos de inicio da partida
    int pontosJogo = 5; //Pontos para cada pergunta correta
    int contador = 0; //Contador de perguntas
    char respostaUser; //Recebe resposta do usuário

    vector<Perguntas> questoes = databasePerguntas(_path); // Gera os objetos Perguntas
    vector<string> respostas; // Recebe de forma temporária apenas as respostas
    random_device rd;
    mt19937 generator(rd());

    shuffle( questoes.begin(), questoes.end(), generator ); //mistura objetos no vector

    for(const auto& questao : questoes) {
        contador++;

        respostas.clear(); // limpar vector
        respostas.push_back(questao.respostaA);
        respostas.push_back(questao.respostaB);
        respostas.push_back(questao.respostaC);
        respostas.push_back(questao.respostaD);

        shuffle( respostas.begin(), respostas.end(), generator ); //mistura objetos no vector

        limparTela();

        cout << corLetra("azul") << corFundo("branco") << "QuizVerse" << resetCor() << endl;
        cout << corLetra("ciano");
        consultarNome(userEmail);
        cout << " |  Pontos da partida : " << pontosUser << " | " << contador << "/10" << resetCor() << endl;
        cout << "" << endl;            
        cout << "Tema: " << questao.tema << endl; //Tema
        cout << "Pergunta:" << endl;
        cout << questao.pergunta << endl; //Pergunta
        cout << respostas[0] << endl; //Resposta A
        cout << respostas[1] << endl; //Resposta B
        cout << respostas[2] << endl; //Resposta C
        cout << respostas[3] << endl; //Resposta D
        cout << "" << endl;
        cout << "Insira a letra que corresponde com a resposta, antes que o tempo acabe!" << endl;
        cin >> respostaUser;

        if(respostaUser == questao.respostaCorreta){
            cout << corLetra("verde") << "Resposta Correta!" << resetCor() << endl;
            cout << corLetra("magenta") << "Boa! +" << pontosJogo << resetCor() << endl;
            pontosUser += pontosJogo;
            sleep(1);
            limparTela();
            
        } else{ 
            cout << corLetra("vermelho") << "Resposta Errada!" << resetCor() << endl;
            sleep(1);
            limparTela();
            }

        // controle de fim de while da leitura de arquivo
        if (contador == 10){
            int _pontosUser = consultarPontos(userEmail) + pontosUser;                
            modificarPontos(userEmail, _pontosUser); //Salva os pontos da partida no database
            return pontosUser;
            break;
        }                       
    }

    return 1;
}

int resetPontos(string userEmail){
    //Recebe o argumento de email e após a confirmação apaga a conta
    int opcao;
    int pontosUser = 0;

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - RESET DE PONTOS - ¦ - |" << resetCor() << endl;
    cout << corLetra("vermelho") << "Tem certeza que deseja fazer o reset de pontos ?" << resetCor() << endl;
    cout << corLetra("vermelho") << "1 - SIM!" << resetCor() << endl;
    cout << corLetra("azul") << "2 - Não, voltar para menu anterior." << resetCor() << endl;
    cin >> opcao;

    if (opcao == 1){
        modificarPontos(userEmail, pontosUser);
        limparTela();        
        cout << corLetra("vermelho") << "Reset de pontos realizado com sucesso." << resetCor() << endl;
        cout << "";
        pressione();
        return 0;
    }
    return 1;
}

void regras() {

    cout << "Regras do jogo Quiz " << endl;
    cout << corLetra("azul") << "---------------------------------------------------------------------------------------------" << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << "1- Registar os dados do jogodar iniciando com login-signin;                                " << corLetra("azul") << "|"  << resetCor() << endl; 
    cout << corLetra("azul") << "|"  << resetCor() << "2- Após a registo o jogador, escolher o tema do jogo e os três níveis de dificuldade;      " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << "3- Inicio do Jogo:                                                                         " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " - Ao selecionar o tema e o nível de dificuldade, são apresentadas 10 perguntas;           " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " - Para cada pergunta terá 4 respostas com seu tempo e dentre elas uma é a certa;          " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " - Cada resposta certa o jogador ganha 5 pontos e a reposta errada não ganha nenhum ponto. " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << "4- Fim do Jogo:                                                                            " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " - Ao responder todas as perguntas o sistema irá partilhar pontos adquiridos nessa rodada  " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << "   mais pontos totais.                                                                     " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << "5- Adicionais:                                                                             " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " -Os jogadores têm a opção de eliminar a sua conta e todos os dados associados a ela;      " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " -Os jogadores podem redefinir a sua pontuação para zero, começando do início;             " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "|"  << resetCor() << " -Caso um jogador esqueça a sua password, fornecemos o mecanismo para recuperá-lo.         " << corLetra("azul") << "|"  << resetCor() << endl;
    cout << corLetra("azul") << "---------------------------------------------------------------------------------------------" << resetCor() << endl;
}


#endif
