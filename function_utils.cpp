#include <stdlib.h>
#include <unistd.h>
#include <iostream>
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

#endif
