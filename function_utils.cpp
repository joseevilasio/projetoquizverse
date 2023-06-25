#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
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

void load(){
    //A função imprime na tela loading de 0% até 100%    
    
    for (int cont = 1; cont < 101; cont++){

        cout.flush();
        cout << "" << cont << "% ";
        usleep(60000);
        limparTela();      
        cout.flush();       
        
    }
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
}

string resetCor(){
    //Reseta a cor
    string reset = "\033[0m";

    return reset;

}


#endif
