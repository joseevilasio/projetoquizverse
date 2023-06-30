#include <iostream>
#include <string>
#include "function_utils.cpp"
#include "function_signin.cpp"
#include "function_database.cpp"
#ifndef FUNCTION_LOGIN_H
#define FUNCTION_LOGIN_H

using namespace std;

struct tipoUsuario {
    // struct para armazenar os dados do usuário
    string nomeCompleto, email, password, pergunta, resposta;
    int pontos = 0;
    };

int validarPassword(string userEmail, string password){
    //Recebe um argumento com string e valida se o password é o que consta no banco de dados
       
    ifstream arquivo(path("database.txt"));  // Abre o arquivo para leitura
    vector<tipoUsuario> usuarios; //Recebe as structs
    int contador = 0;
    
    if (arquivo.is_open()){
        string linha;
        
        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }

            usuarios.push_back({dados[0], dados[1], dados[2], dados[3], dados[4], stoi(dados[5])});

            if (userEmail == usuarios[contador].email){  
                if(password == usuarios[contador].password){
                    return 0;
                    break;                
                }  
            }
            contador ++;
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return 1;
}

bool recuperacaoPassword(){
    //Solicita email e exibe pergunta de recuperação e valida se o pergunta é o que consta no banco de dados
    ifstream arquivo(path("database.txt"));  // Abre o arquivo para leitura
    string resposta, email;
    int quantErros = 0;

    cabecalho("RECUPERAÇÃO DE PALAVRA-PASSE");

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
                        pressione("continuar");
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

    cabecalho("LOGIN");    

    while(quantErros != 3){

        cout << endl;
        cout << "Email: ";
        getline(cin, userEmail);
        cout << endl;

        cout << "Palavra-passe: ";        
        userPassword = mascararPassword();
        cout << endl;

        if ( validarPassword(userEmail, userPassword) == 0){
            return true;
            break;
                

            } else{
                //Se password for inválido, diminuir quantidades de tentativas.
                quantErros += 1;
                limparTela();
                cout << corLetra("vermelho") << endl;
                cout << "Palavra-passe inválida ou Email inválido - Tente novamente [" << quantErros << "]" << resetCor() << endl;
                cabecalho("LOGIN");  
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

int eliminarConta(string userEmail){
    //Recebe o argumento de email e após a confirmação apaga a conta
    int opcao;
    string nomeArquivo = path("database.txt");
    int linhaParaEliminar = consultarLinhadeArquivo(userEmail);

    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - ELIMINAR CONTA - ¦ - |" << resetCor() << endl;
    cout << corLetra("vermelho") << "Tem certeza que deseja eliminar a conta ?" << resetCor() << endl;
    cout << corLetra("vermelho") << "1 - SIM!" << resetCor() << endl;
    cout << corLetra("azul") << "2 - Não, voltar para menu anterior." << resetCor() << endl;
    cin >> opcao;

    if (opcao == 1){
        eliminarLinhaArquivo(nomeArquivo, linhaParaEliminar);
        limparTela();        
        cout << corLetra("vermelho") << "Conta eliminada com sucesso." << resetCor() << endl;
        return 0;
    }
    return 1;
}

int consultarPontos(string userEmail){
    //recebe email e exibe os pontos registados
    ifstream arquivo(path("database.txt"));  // Abre o arquivo para leitura
    
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
                int pontos = stoi(dados[5]);
                return pontos;
                break;  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return 0;
}

void consultarNome(string userEmail){
    //recebe email e exibe o nome cadastrado
    ifstream arquivo(path("database.txt"));  // Abre o arquivo para leitura
    
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
