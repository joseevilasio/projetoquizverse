#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#ifdef _WIN32
    // Inclua as bibliotecas específicas do Windows aqui
    #include <canio.h>   
#elif __linux__
    // Inclua as bibliotecas específicas do Linux aqui
    #include <termios.h>    

#endif

#ifndef FUNCTION_UTILS_H
#define FUNCTION_UTILS_H

using namespace std;

void limparTela(){
    //Limpa tela do terminal
    #ifdef _WIN32
        system("CLS");
    #elif defined __unix__
        system("clear");
    #endif
}

void pressione() {
    //Verifica qual o sistema e captura
    cout << "Pressione enter para continuar ..." << endl;    
    #ifdef _WIN32
        getch();
    #elif defined __unix__
        getchar();
    #endif

    limparTela();
}

void load(){
    //A função imprime na tela loading de 0% até 100%    
    
    for (int cont = 1; cont < 101; cont++){        
        cout.flush();
        cout << "" << cont << "% ";
        usleep(50000);
        limparTela();      
        cout.flush(); 
    }
    limparTela();  
}

string corLetra(string cor) {
    // Recebe um argumento de cor     
    // Disponiveis

    //cores letras
    string vermelho = "\033[1;31m";
    string verde = "\033[1;32m";
    string azul = "\033[1;34m";
    string branco = "\033[1;37m";
    string magenta = "\033[1;35m";
    string ciano = "\033[1;36m";
    
    if (cor == "vermelho"){
        return vermelho;
    }else if (cor == "verde"){
        return verde;
    }else if (cor == "azul"){
        return azul;
    }else if (cor == "branco"){
        return branco;
    }else if (cor == "magenta"){
        return magenta;
    }else if (cor == "ciano"){
        return ciano;
    }else{"";}

    return "";
}

string corFundo(string cor) {
    // Recebe um argumento de cor 
    //cores fundo
    string vermelho = "\033[1;41m";
    string verde = "\033[1;42m";
    string azul = "\033[1;44m";
    string branco = "\033[1;47m";
    string magenta = "\033[1;45m";
    string ciano = "\033[1;46m";   
    
    if (cor == "vermelho"){
        return vermelho;
    }else if (cor == "verde"){
        return verde;
    }else if (cor == "azul"){
        return azul;
    }else if (cor == "branco"){
        return branco;
    }else if (cor == "magenta"){
        return magenta;
    }else if (cor == "ciano"){
        return ciano;
    }else{"";}

    return "";
}

string resetCor(){
    //Reseta a cor
    string reset = "\033[0m";

    return reset;

}

void loadX(){
    //teste para aprimorar load   
    
    for (int cont = 1; cont < 101; cont++){        
        
        cout << corFundo("branco") << "  ";
        load();

    } 
}


string calcularEspaco(int tamanho) {
    string espaco = " ";    
    string resultado;

    int multiplicador = 21 - tamanho;

    for (int i = 0; i < multiplicador; i++) {
        resultado += espaco;
    }

  return resultado;
    
}

//Tela Inicial

void telaInicial(){

    cout << "" << endl;
    cout << "" << endl;
    cout << "QuizVerse" << endl;
    cout << "" << endl;
    cout << "" << endl;
    pressione();
}

//Tela de Saida

void telaSaida(){

    int opcao;

    cout << "" << endl;
    cout << "" << endl;
    cout << "QuizVerse" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Projeto Realizado por: " << endl;
    cout << "Hugo Magalhaes" << endl;
    cout << "Jose Junior" << endl;
    cout << "Patricia Correia" << endl;
    cin >> opcao;
}

void tempo(){
    //A função imprime na tela o tempo
    int segundos = 4;
    int segundosFinais = segundos / 2;
    
    for (int cont = segundos; cont > -1; cont--){

        usleep(1000000);        
        if (cont > segundosFinais) {
            cout << corLetra("branco") << "00:" << cont << " >>";            
            cout.flush();
            cout << "\033[2K"; // Limpa a linha atual
            cout << "\033[0G"; // Retorna para a coluna inicial
            
        } else {
            cout << corLetra("vermelho") << "00:" << cont << " >>";            
            cout.flush();
            cout << "\033[2K"; // Limpa a linha atual
            cout << "\033[0G"; // Retorna para a coluna inicial
            }
    }
        
    cout << resetCor;

    //return 0; 
}

#endif
