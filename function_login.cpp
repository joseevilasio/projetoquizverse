#include <iostream>
#include <string>
#include "function_utils.cpp"
#include "function_signin.cpp"
#ifndef FUNCTION_LOGIN_H
#define FUNCTION_LOGIN_H

using namespace std;

bool validarPassword(string userEmail, string password){
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
                
            if (userEmail == dados[1]){
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
    int quantErros = 0;

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - RECUPERAÇÃO DE PALAVRA-PASSE - ¦ - |" << resetCor() << endl;

    cout << "Digite seu email: ";
    cin.ignore();    
    cin >> email;
    if (validarEmail(email) == false){
        cout << corLetra("vermelho") << "Email não está cadastrado!" << resetCor();
        return false;
    }
    
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

                while(quantErros != 3){
                    cout << corLetra("ciano") << dados[3] << resetCor() << endl;
                    cin.ignore();
                    getline(cin, resposta);                
                    cout << "" << endl;                

                    if(resposta == dados[4]){ //Se a resposta corresponder o que está no no banco de dados
                        limparTela();
                        cout << corLetra("vermelho") << corFundo("branco") << "Atenção! Sua palavra passe:" << endl;
                        cout << corLetra("verde") << corFundo("branco") << dados[2] << resetCor() << endl;
                        cout << "" << endl;                    
                        usleep(10000000);
                        return true;
                        break;

                    } else{ //Se resposta for inválida, diminuir quantidades de tentativas.
                        quantErros += 1;
                        limparTela();
                        cout << corLetra("vermelho") << endl;
                        cout << "Resposta de recuperação inválida - Tente novamente [" << quantErros << "]" << resetCor() << endl;}
                }
            }   
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return false;
}

bool login(string &userEmail){
    //Solicita email e senha do usuario para validar    
    int quantErros = 0;
    string userPassword;

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

    return false;
}

void eliminarConta(){
    //Recebe o argumento de email e após a confirmação apaga a conta
    int opcao;

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - ELIMINAR CONTA - ¦ - |" << resetCor() << endl;
    cout << corLetra("vermelho") << "Tem certeza que deseja eliminar a conta ?" << resetCor() << endl;
    cout << corLetra("vermelho") << "1 - SIM!" << resetCor() << endl;
    cout << corLetra("azul") << "2 - Não, voltar para menu anterior." << resetCor() << endl;
    cin >> opcao;

    if (opcao == 1){

    }
}

void consultarPontos(string userEmail){
    //recebe email e exibe os pontos registados
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
                
            if (userEmail == dados[1]){
                cout << dados[5];
                break;  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
}

void consultarNome(string userEmail){
    //recebe email e exibe o nome cadastrado
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
                
            if (userEmail == dados[1]){
                cout << dados[0];
                break;  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
}

#endif
