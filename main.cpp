#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <fstream>
#include <unistd.h>

using namespace std;

void limparTela(){
    //Limpa tela do terminal
    system("CLS");
}

int signin(){
    //Cadastro de usuário, recebe informações sobre usuário e armezena em arquivo txt

    struct tipoUsuario {
        // struct para armazenar os dados do usuário
        string nomeCompleto, email, password, pergunta, resposta;
        int pontos = 0;
    };

    typedef struct tipoUsuario tipoUsuario; //facilitar a leitura de criação da struct

    tipoUsuario usuario; //usuario agora é uma objeto do tipo struct
    
    int opcao; //variável utilizada na escolha da pergunta de recuperação da palavra passe
    bool condicao = true; //variavel de controle da condição de parada do while

    cout << "|  - - REGISTO - - |" << endl;
    cout << "Digite seu nome: ";
    getline(cin, usuario.nomeCompleto);
    cout << "Digite seu email: ";
    //#TODO adicionar função para verificar se o email já existe no banco de dados
    cin >> usuario.email;
    cout << "Digite seu password: ";
    cin >> usuario.password;
    
    while (condicao) {
        cout << " -- Escolha a pergunta de recuperação de conta -- " << endl;
        cout << "1 - Qual é o nome do seu formador preferido?" << endl;
        cout << "2 - Qual foi o nome do seu primeiro pet?" << endl;
        cout << "3 - Qual a cidade que você nasceu?" << endl;    
        cin >> opcao;

        switch (opcao) {
            case 1:
                usuario.pergunta = "Qual é o nome do seu formador preferido?";
                condicao = false;
                cout << "1 - Qual é o nome do seu formador preferido?" << endl;               
                break;
            case 2:
                usuario.pergunta = "Qual foi o nome do seu primeiro pet?";
                condicao = false;
                cout << "2 - Qual foi o nome do seu primeiro pet?" << endl;  
                break;
            case 3:
                usuario.pergunta = "Qual a cidade que você nasceu?";
                condicao = false;
                cout << "3 - Qual a cidade que você nasceu?" << endl; 
                break;                
            default:
                cout << "A " << opcao << " é uma entrada incorreta! - Tente novamente." << endl;
                break;
        }
    }

    getline(cin, usuario.resposta);
    cout << "" << endl;
    //#TODO adicionar funcão loading
    cout << "Cadastro realizado com sucesso!!!";
    limparTela();

    ofstream arquivo("assets/database.txt", ios::app);

    if (arquivo.is_open()) {
        arquivo << "" << usuario.nomeCompleto << "," << usuario.email << "," << usuario.password << "," << usuario.pergunta << "," << usuario.resposta << "," << usuario.pontos << endl;
        arquivo.close();
    } else {
        cout << "Falha na gravação do arquivo." << endl;
    }

    return 0;
}


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
