#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <cctype>

using namespace std;

void limparTela(){
    //Limpa tela do terminal
    system("CLS");
}

//Tela Inicial
char telaInicial(){

    char opcao;

    cout << "TriviaPlanet";
    while(opcao != 'B') {

    cout << "" << endl;
    cout << "A - Entrar" << endl;
    cout << "B - Sair" << endl;
    cin >> opcao;
    opcao = toupper(opcao);

        switch (opcao) {
            case 'A':
            return 'A';
            break;

            case 'B' :
            return 'B';
            break;

            default: cout << "Opção Inválida. Tente Novamente!" << endl;
        }

    }

    return 'A';

}



int main() {
    //Utilizar linguagem local do sistema do usuário.
    setlocale(LC_ALL,"");

    //Declarar todas as variaveis aqui e comentar o que cada uma faz
    int opcao; // variavel utilizada no while de Tela Registo/Login

    //Exibir Tela de Boas Vindas, resulta em um return a (entrar) ou b (sair)
    //inserir funcao
    telaInicial();

    //estruturar um if quando a funcao Boas Vindas tiver pronta
    while (opcao != 3) {

    cout << "" << endl;
    cout << "1 Logín" << endl;
    cout << "2 Signin" << endl;
    cout << "3 Sair" << endl;
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
