#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <vector>
#include "function_utils.cpp"
#ifndef FUNCTION_SIGNIN_H
#define FUNCTION_SIGNIN_H

#ifdef _WIN32
    // Inclua as bibliotecas específicas do Windows aqui
    #include <conio.h>   
#elif __linux__
    // Inclua as bibliotecas específicas do Linux aqui
    #include <termios.h>    
#endif

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

string mascararPassword() {
    //Recebe um password digitado pelo usuário e mascara cada caracte e da um retorno em uma string   

    string password;
    char ch;

     #ifdef _WIN32

        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password += ch;
                cout << "*";
            }
        }

        return password;

    #elif defined __unix__ 
        //estrutura para utilizar em linux
        struct termios oldTermios, newTermios;
        tcgetattr(STDIN_FILENO, &oldTermios);
        newTermios = oldTermios;
        newTermios.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);

        while ((ch = getchar()) != '\n') {
            password += ch;
            cout << "*";
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);

        return password;

    #endif
    
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

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - REGISTO - ¦ - |" << resetCor() << endl;
    cout << "" << endl;

    cout << "Digite seu nome: ";
    cin.ignore(); // Limpa o buffer do cin
    getline(cin, usuario.nomeCompleto);    

    cout << "Digite seu email: ";    
    cin >> usuario.email;

    //Verificar se o email já existe no banco de dados

    if (validarEmail(usuario.email) == true){
        limparTela();
        cout << "___________________________________________" << endl;
        cout << " O email '" << usuario.email << "' já está cadastrado." << endl;
        cout << " Tente novamente ou faça login!" << endl;
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
        pressione();
        return 1;
    }

    cout << "Digite seu password: ";
    cin.ignore();
    usuario.password = mascararPassword();
    
    while (condicao) {
        cout << "" << endl;
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

    cin.ignore(); // Limpa o buffer do cin
    getline(cin, usuario.resposta);
    cout << "" << endl;

    //recurso visual de loading e apresentar que cadastro foi realizado
    limparTela();
    load();
    cout << corLetra("verde") << "Cadastro realizado com sucesso!!!" << endl;
    usleep(500000);

    //abrir o arquivo de database e salvar as informações coletadas
    ofstream arquivo("assets/database.txt", ios::app);

    if (arquivo.is_open()) {
        arquivo << "" << usuario.nomeCompleto << "," << usuario.email << "," << usuario.password << "," << usuario.pergunta << "," << usuario.resposta << "," << usuario.pontos << endl;
        arquivo.close();
    } else {
        cout << "Falha na gravação do arquivo." << endl;
    }

    return 0;
}

#endif
