#include <iostream>
#include <string>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include "function_signin.cpp"
#include "function_utils.cpp"
#include "function_login.cpp"
#include "function_game.cpp"

using namespace std;


int main() {
    //Utilizar linguagem local do sistema do usuário.
    setlocale(LC_ALL, "");

    //Declarar todas as variaveis aqui e comentar o que cada uma faz
    int opcao; // variavel utilizada no while de Tela Registo/Login 
    int opcaoMenuJogo; // variavel utilizada no while do menu jogo
    string userEmail; // variavel de email que será atualizada com email digitado pelo usuario

    //Exibir Tela de Boas Vindas, resulta em um return 0 (entrar) ou 1 (sair)
    //inserir funcao

    //estruturar um if quando a funcao Boas Vindas tiver pronta
    while (opcao != 4) {

    //load();
    
    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - MENU Inicial - QuizVerse - ¦ - |" << resetCor() << endl;
    cout << "" << endl;
    cout << "1 > Login" << endl;
    cout << "2 > Signin" << endl;
    cout << "3 > Recuperar Palavra-Passe" << endl;   
    cout << "4 > Sair" << endl;
    cout << ">>> ";
    cin >> opcao;

        switch (opcao) {

            case 1: //Login
            limparTela();                       

            if (login(userEmail) == true){
                //Após login realizado menu jogo                
                while (opcaoMenuJogo != 6){

                    limparTela();
                    //load();
                    cout << corLetra("azul") << corFundo("branco") << "|  - ¦ - MENU Jogo - QuizVerse - ¦ - |" << resetCor() << endl;
                    cout << corLetra("ciano") << corFundo("branco");
                    consultarNome(userEmail);
                    cout  << " - Total de ";
                    consultarPontos(userEmail);
                    cout << " pontos." << resetCor() << endl;                
                    cout << "" << endl;
                    cout << "1 > Jogar" << endl;
                    cout << "2 > Ranking" << endl;
                    cout << "3 > Reset de Pontos" << endl;   
                    cout << "4 > Regras" << endl;
                    cout << "5 > Eliminar Conta" << endl;
                    cout << "6 > Sair" << endl;
                    cout << ">>> ";
                    cin >> opcaoMenuJogo;
                    limparTela();


                    switch (opcaoMenuJogo){

                        case 1: // Jogar
                        opcaoTema();                        
                        break;

                        case 2: // Ranking                        
                        break;

                        case 3: // Reset de Pontos                        
                        break;

                        case 4: // Regras                        
                        break;

                        case 5: // Eliminar Conta
                        limparTela();                        
                        if (eliminarConta(userEmail) == 0){
                            limparTela();
                            opcaoMenuJogo = 6;
                        }                        
                        break;

                        case 6: // Sair                        
                        break;

                        default: cout << "A " << opcaoMenuJogo << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;

                    }
                }
                
            } else{
                load();                
                if (recuperacaoPassword() == true){
                limparTela();
                load();
                // redirecionar para o menu inicial
                } else{opcao = 4;} //adicionar tela de bloqueio
            }            
            break;

            case 2: //Registo
            limparTela();
            signin();
            break;

            case 3: //Recuperar palavra passe
            limparTela();
            load();            
            if (recuperacaoPassword() == true){
                limparTela();
                load();
                // redirecionar para o menu inicial
            } else{opcao = 4;} //adicionar tela de bloqueio
            break;

            case 4: //Sair
            limparTela();
            //inserir tela de despedida
            cout << corLetra("vermelho") << corFundo("branco") << "Tela Despedida" << resetCor() << endl;
            break;
            exit(0);

            default: cout << "A " << opcao << " é uma entrada incorreta! - Tente novamente." << endl; limparTela(); break;
        }
    }

    return 0;

}
