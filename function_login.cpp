#include <iostream>
#include <string>
#include "function_utils.cpp"
#include "function_signin.cpp"
#include "function_database.cpp"
#ifndef FUNCTION_LOGIN_H
#define FUNCTION_LOGIN_H

using namespace std;

int validarPassword(string userEmail, string password){
    //Recebe um argumento com string e valida se o password é o que consta no banco de dados
       
    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail == usuario.email){
            if(password == usuario.password){
                return 0;
                break;                
                }
        }
    }
    return 1;
}

bool recuperacaoPassword(){
    //Solicita email e exibe pergunta de recuperação e valida se o pergunta é o que consta no banco de dados
    
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

    for(const auto& usuario : databaseUsuarios()) {    
       
        if (email == usuario.email){
            while(quantErros != 3){
                cout << corLetra("ciano") << usuario.pergunta << resetCor() << endl;
                cin.ignore();
                getline(cin, resposta);                
                cout << "" << endl;                

                if(resposta == usuario.resposta){ //Se a resposta corresponder o que está no no banco de dados
                    limparTela();
                    cout << corLetra("vermelho") << corFundo("branco") << "Atenção! Sua palavra passe:" << endl;
                    cout << corLetra("verde") << corFundo("branco") << usuario.password << resetCor() << endl;
                    cout << "" << endl;                    
                    pressione();
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
        getline(cin, userEmail);
        cout << endl;

        cout << "Palavra-passe: ";
        userPassword = mascararPassword();
        cout << endl;

        if ( validarPassword(userEmail, userPassword) == 0){
            return true;
            break;
                
        } else {
            //Se password for inválido, diminuir quantidades de tentativas.
            quantErros += 1;
            limparTela();            
            cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - LOGIN - ¦ - |" << resetCor() << endl;
            cout << corLetra("vermelho") << endl;
            cout << "Palavra-passe inválida ou Email inválido - Tente novamente [" << quantErros << "]" << resetCor() << endl;
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
    
    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - ELIMINAR CONTA - ¦ - |" << resetCor() << endl;
    cout << corLetra("vermelho") << "Tem certeza que deseja eliminar a conta ?" << resetCor() << endl;
    cout << corLetra("vermelho") << "1 - SIM!" << resetCor() << endl;
    cout << corLetra("azul") << "2 - Não, voltar para menu anterior." << resetCor() << endl;
    cin >> opcao;

    if (opcao == 1){
        eliminarDados(userEmail);
        limparTela();        
        cout << corLetra("vermelho") << "Conta eliminada com sucesso." << resetCor() << endl;
        return 0;
    }
    return 1;
}

int consultarPontos(string userEmail){
    //recebe email e exibe os pontos registados    
    
    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail == usuario.email){            
            return usuario.pontos;
            break;                
            }
    }    
    return 0;
}

void consultarNome(string userEmail){
    //recebe email e exibe o nome cadastrado    
    
    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail == usuario.email){            
            cout << usuario.nomeCompleto;
            break;                
        }
    } 
}

#endif
