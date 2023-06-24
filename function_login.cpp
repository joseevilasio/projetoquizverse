#include <iostream>
#include <string>
#include "function_utils.cpp"
#include "function_signin.cpp"
#ifndef FUNCTION_LOGIN_H
#define FUNCTION_LOGIN_H

using namespace std;

bool validarPassword(string email, string password){
    //Recebe um argumento com string e valida se o password é o que consta no banco de dados
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
                if(password == dados[2]){
                    return true;
                    break;                
                }  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return false;
}

bool recuperacaoPassword(){
    //Solicita email e exibe pergunta de recuperação e valida se o pergunta é o que consta no banco de dados
    ifstream arquivo("assets/database.txt");  // Abre o arquivo para leitura
    string resposta, email;

    cout << "Digite seu email: ";    
    cin >> email;
    
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
                cout << corLetra("ciano") << dados[3] << resetCor() << endl;
                cin.ignore();
                getline(cin, resposta);                
                cout << "" << endl;

                if(resposta == dados[3]){
                    cout << corLetra("verde") << corFundo("branco") << dados[3] << endl;
                    return true;
                    break;                
                } else{cout << "erro";}
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return false;
}

bool login(){
    //Solicita email e senha do usuario para validar    
    int quantErros = 0;
    string userEmail, userPassword;

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - LOGIN - ¦ - |" << resetCor() << endl;    

    while(quantErros != 3){

        cout << endl;
        cout << "Email: ";
        cin.ignore();
        cin >> userEmail;
        cout << endl;

        cout << "Palavra-passe: ";
        cin.ignore();
        userPassword = mascararPassword();;
        cout << endl;       

        if (validarPassword(userEmail, userPassword) == true){
                return true;
                break;
            } else{
                //Se password for inválido, diminuir quantidades de tentativas.
                quantErros += 1;
                limparTela();
                cout << corLetra("vermelho") << endl;
                cout << "Palavra-passe inválida ou Email inválido - Tente novamente [" << quantErros << "]" << resetCor() << endl;
                cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - LOGIN - ¦ - |" << resetCor() << endl;  
            }
    }

    if (quantErros == 3){
        limparTela();
        cout << corLetra("vermelho") << endl;
        cout << "Usuário excedeu as quantidades de tentativas de login. 3 erros." << resetCor() << endl;
        return false;
    }
}

#endif
