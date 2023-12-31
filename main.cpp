#include <iostream>
#include <string>
#include <stdlib.h>
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
    int opcaoTema, opcaoDificuldade; // variavel utilizada para definir tema e dificuldade
    string press;

    //Exibir Tela de Boas Vindas, resulta em um return A (entrar), B (sair) ou default (Erro).
    

    //estruturar um if quando a funcao Boas Vindas tiver pronta
    while (opcao != 4) {

        telaInicial();

        load();
        
        cabecalho("MENU Inicial");
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
                    cabecalho("MENU Jogo");
                    cout << corLetra("verde") << " ";
                    consultarNome(userEmail);
                    cout  << " - Total de " << consultarPontos(userEmail) << " pontos." << resetCor() << endl;
                    cout << "" << endl;
                    cout << "1 > Jogar" << endl;
                    cout << "2 > Ranking" << endl;
                    cout << "3 > Reset de Pontos" << endl;   
                    cout << "4 > Regras" << endl;
                    cout << "5 > Eliminar Conta" << endl;
                    cout << "6 > Voltar ao menu inicial" << endl;
                    cout << ">>> ";                    
                    cin >> opcaoMenuJogo;
                    limparTela();


                    switch (opcaoMenuJogo){

                        case 1: // Jogar
                        if (escolherTema(opcaoTema, opcaoDificuldade) == 0){                            
                            jogar(opcaoTema, opcaoDificuldade, userEmail);
                        }                        
                        break;

                        case 2: // Ranking
                        limparTela();
                        ranking();
                        cin.ignore();
                        pressione("continuar");
                        break;

                        case 3: // Reset de Pontos 
                            limparTela();
                            resetPontos(userEmail);
                            break;

                        case 4: // Regras
                            limparTela();
                            cin.ignore();
                            regras();                       
                            break;

                        case 5: // Eliminar Conta
                        limparTela();                        
                        if (eliminarConta(userEmail) == 0){
                            limparTela();
                            opcaoMenuJogo = 6;
                        }                        
                        break;

                        case 6: // Voltar
                        cin.clear();                      
                        break;

                        default:
                        limparTela();
                        cout << corLetra("vermelho") << "'" << opcaoMenuJogo << "' é uma entrada incorreta! - Tente novamente." << resetCor() << endl;
                        cin.ignore();            
                        pressione("continuar");
                        cin.clear();
                        limparTela();                      
                        break;

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
            } else {
            cin.ignore();
            pressione("voltar"); }
            break;

            case 4: //Sair      
            telaSaida();
            exit(0);
            break;

            default:
            limparTela();
            cout << corLetra("vermelho") << "'" << opcao << "' é uma entrada incorreta! - Tente novamente." << resetCor() << endl;
            cin.ignore();            
            pressione("continuar");
            cin.clear();
            break;
        }
    }

    return 0;

}
