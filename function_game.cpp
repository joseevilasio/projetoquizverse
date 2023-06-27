#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "function_utils.cpp"
#include "function_login.cpp"
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

    string path;

    switch (opcaoTema) {
        case 1: // 1 > Tema Geografia e Cultura
            if (opcaoDificuldade == 1){path = "assets/1_geografia_1_faceis.txt";}
            else if (opcaoDificuldade == 2){path = "assets/1_geografia_2_normais.txt";}
            else if (opcaoDificuldade == 3){path = "assets/1_geografia_1_dificeis.txt";}
            break;

        case 2: // 2 > Tema Fisica e Matemática
            if (opcaoDificuldade == 1){cout << "";}
            else if (opcaoDificuldade == 2){cout << "";}
            else if (opcaoDificuldade == 3){cout << "";}
            break;


        case 3: // 3 > Tema Química e Biologia
            if (opcaoDificuldade == 1){cout << "";}
            else if (opcaoDificuldade == 2){cout << "";}
            else if (opcaoDificuldade == 3){cout << "";}
            break;
        
        default:
            break;
    }

    ifstream arquivo(path);

    int pontosUser = 0;
    int pontosJogo = 10;
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

            // controle de termino
            if (contador == 11){
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

            contador++;

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


#endif
