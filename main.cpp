#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include "function_signin.cpp"
#include "function_utils.cpp"
#include "function_login.cpp"

using namespace std;


int main() {
    //Utilizar linguagem local do sistema do usuário.
    setlocale(LC_ALL, "");

    //Declarar todas as variaveis aqui e comentar o que cada uma faz
    int opcao; // variavel utilizada no while de Tela Registo/Login    

    //Exibir Tela de Boas Vindas, resulta em um return 0 (entrar) ou 1 (sair)
    //inserir funcao

    //estruturar um if quando a funcao Boas Vindas tiver pronta
    while (opcao != 4) {
    
    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - MENU Inicial - QuizVerse - ¦ - |" << resetCor() << endl;
    cout << "" << endl;
    cout << "1 > Login" << endl;
    cout << "2 > Signin" << endl;
    cout << "3 > Recuperar Palavra-Passe" << endl;   
    cout << "4 > Sair" << endl;
    cout << ">>> ";
    cin >> opcao;

        switch (opcao) {

            case 1: //Login
            limparTela();
            //Tela de login
            if (login() == true){
                cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - MENU Jogo - QuizVerse - ¦ - |" << resetCor() << endl;
                //inserir menu de usuario logado
                // opções de jogar, regras, eliminar, ranking, reset de pontos

            } else{
                load();
                limparTela();                
                if (recuperacaoPassword() == true){
                limparTela();
                load();
                // redirecionar para o menu inicial
                } else{opcao = 4;} //adicionar tela de bloqueio
            }            
            break;

            case 2: //Registo
            limparTela();
            signin();
            break;

            case 3: //Recuperar palavra passe
            limparTela();
            load();
            limparTela();            
            if (recuperacaoPassword() == true){
                limparTela();
                load();
                // redirecionar para o menu inicial
            } else{opcao = 4;} //adicionar tela de bloqueio
            break;

            case 4: //Sair
            limparTela();
            //inserir tela de despedida
            cout << corLetra("vermelho") << corFundo("branco") << "Tela Despedida" << resetCor() << endl;
            break;
            exit(0);

            default: cout << "A " << opcao << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
        }
    }

}
