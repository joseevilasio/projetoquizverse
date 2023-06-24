#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include "function_signin.cpp"
#include "function_utils.cpp"

using namespace std;


int main() {
    //Utilizar linguagem local do sistema do usuário.
    setlocale(LC_ALL, "");

    //Declarar todas as variaveis aqui e comentar o que cada uma faz
    int opcao; // variavel utilizada no while de Tela Registo/Login    

    //Exibir Tela de Boas Vindas, resulta em um return 0 (entrar) ou 1 (sair)
    //inserir funcao

    //estruturar um if quando a funcao Boas Vindas tiver pronta
    while (opcao != 3) {

    cout << "" << endl;
    cout << "1 > Login" << endl;
    cout << "2 > Signin" << endl;
    cout << "3 > Sair" << endl;
    cout << ">>>";
    cin >> opcao;

        switch (opcao) {
            case 1:
            limparTela();            
            //inserir tela de login
            cout << "Tela Login" << endl;            
            exit(0);
            break;

            case 2: 
            limparTela();
            //inserir tela de cadastro
            cout << "Tela Cadastro" << endl;
            signin();   
            break;

            case 3: 
            limparTela();
            //inserir tela de despedida
            cout << "Tela Despedida" << endl;
            break;

            default: cout << "A " << opcao << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
        }
    }

}
