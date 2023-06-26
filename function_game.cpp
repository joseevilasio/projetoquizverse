#include <iostream>
#include <string>
#include "function_utils.cpp"
#ifndef FUNCTION_GAME_H
#define FUNCTION_GAME_H

using namespace std;

string opcaoTema() {
    // Abre menu de temas e dificuldades e retorna string com as informações
    int opcaoTema, opcaoDificuldade;

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
            break;

        case 4:
            // Voltar
            break;

        default: cout << "A " << opcaoTema << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
    }    
}

#endif
