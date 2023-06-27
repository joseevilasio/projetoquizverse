#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "function_utils.cpp"
#include "function_login.cpp"
#include "function_database.cpp"

#ifndef FUNCTION_GAME_H
#define FUNCTION_GAME_H

using namespace std;

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
    // ranking    
    ifstream arquivo("assets/database.txt");  // Abre o arquivo para leitura
    int opcao;

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - Ranking - QuizVerse - ¦ - |" << resetCor() << endl;
    cout << corLetra("ciano") << "------------------------------------" << endl;     
    cout << "| # | Nome              | Pontos   |" << endl;
    cout << "------------------------------------" << endl;       
    
    if (arquivo.is_open()){
        string linha;       

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;
            
            
            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }

            size_t tamanhoString = dados[0].size();

            cout << "1   " << dados[0];
            cout << calcularEspaco(tamanhoString);
            cout << dados[5] << endl;            
        }

        cout << "------------------------------------" << resetCor() << endl;
        cout << "" << endl;
        cout << "1 > Voltar ao menu" << endl;
        cout << ">>> ";
        cin >> opcao; 

        arquivo.close();

    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
}

int jogar(int opcaoTema, int opcaoDificuldade, string userEmail) {
    // Recebe as informações de escolha de tema e dificuldade, email e inicia leitura de arquivo de perguntas
    string path;

    switch (opcaoTema) {
        case 1: // 1 > Tema Geografia e Cultura
            if (opcaoDificuldade == 1){path = "assets/1_geografia_1_faceis.txt";}
            else if (opcaoDificuldade == 2){path = "assets/1_geografia_2_normais.txt";}
            else if (opcaoDificuldade == 3){path = "assets/1_geografia_3_dificeis.txt";}
            break;

        case 2: // 2 > Tema Fisica e Matemática
            if (opcaoDificuldade == 1){path = "assets/2_matematica_1_faceis.txt";}
            else if (opcaoDificuldade == 2){path = "assets/2_matematica_2_normais.txt";}
            else if (opcaoDificuldade == 3){path = "assets/2_matematica_3_dificeis.txt";}
            break;


        case 3: // 3 > Tema Química e Biologia
            if (opcaoDificuldade == 1){path = "assets/3_quimica_1_faceis.txt";}
            else if (opcaoDificuldade == 2){path = "assets/3_quimica_2_normais.txt";}
            else if (opcaoDificuldade == 3){path = "assets/3_quimica_3_dificeis.txt";}
            break;
        
        default:
            break;
    }

    ifstream arquivo(path); // recebe de acordo com tema e dificuldade escolhida o path do arquivo de perguntas

    int pontosUser = 0; //Pontos de inicio da partida
    int pontosJogo = 5; //Pontos para cada pergunta correta
    int contador = 1;
    
    if (arquivo.is_open()){
        string linha;        

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;            

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }

            char respostaUser;
            char respostaCorreta = 'a';
            contador++;

            // controle de fim de while da leitura de arquivo
            if (contador == 11){
                int _pontosUser = consultarPontos(userEmail) + pontosUser;                
                modificarPontos(userEmail, _pontosUser); //Salva os pontos da partida no database
                return pontosUser;
                break;
            } 

            cout << corLetra("azul") << corFundo("branco") << "QuizVerse" << resetCor() << endl;
            cout << corLetra("ciano");
            consultarNome(userEmail);
            cout << " |  Pontos da partida : " << pontosUser << " | " << contador << "/10" << resetCor() << endl;
            cout << "" << endl;            
            cout << "Tema: " << dados[0] << endl; //Tema
            cout << "Pergunta:" << endl;
            cout << dados[1] << endl; //Pergunta
            cout << dados[2] << endl; //Resposta A
            cout << dados[3] << endl; //Resposta B
            cout << dados[4] << endl; //Resposta C
            cout << dados[5] << endl; //Resposta D
            cout << ">>> ";
            cin >> respostaUser;            

            if(respostaUser == respostaCorreta){
                cout << corLetra("verde") << "Resposta Correta!" << resetCor() << endl;
                cout << corLetra("magenta") << "Boa! +10" << resetCor() << endl;
                pontosUser += pontosJogo;
                usleep(1000000);
                limparTela();
                
            } else{ 
                cout << corLetra("vermelho") << "Resposta Errada!" << resetCor() << endl;
                usleep(1000000);
                limparTela();
                }                      
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
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
        cout << "Pressione qualquer tecla para voltar ao menu." << endl;
        //adicionar um getch
        return 0;
    }
    return 1;
}


#endif
