#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


bool validarEmail(string email){
    //Recebe um argumento com string e valida se o email já existe no banco de dados
    ifstream arquivo("assets/database.txt");  // Abre o arquivo para leitura
    
    if (arquivo.is_open()){
        string linha;

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }
                
            if (email == dados[1]){               
                return true;
                break;
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return false;
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
