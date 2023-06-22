#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>

using namespace std;

void limparTela(){
    system("CLS");
}



int main() {
    //Utilizar linguagem local do sistema do usuário.
    setlocale(LC_ALL, "");

    //Exibir Tela de Boas Vindas, resulta em um return
    boasvindas();

    while (opcao != 3) {

    cout << "" << endl;
    cout << "1 Login" << endl;
    cout << "2 Signin" << endl;
    cout << "3 Sair" << endl;
    cout << ">>>";
    cin >> opcao;

        switch (opcao) {
            case 1:
            limparTela();
            if (login(email, password) == 0){
                limparTela();
                boasVindas2(nomeCompleto);
            }
            exit(0);
            break;

            case 2: limparTela(); signin(nomeCompleto, email, password); time(); limparTela(); break;
            case 3: limparTela(); despedida(); break;
            default: cout << "A " << opcao << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
        }
    }

}
