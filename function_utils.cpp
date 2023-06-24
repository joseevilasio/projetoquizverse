#include <stdlib.h>
#include <unistd.h>
#ifndef FUNCTION_UTILS_H
#define FUNCTION_UTILS_H


void limparTela(){
    //Limpa tela do terminal
    #ifdef _WIN32
        system("CLS");
    #elif defined __unix__
        system("clear");
    #endif
}

#endif
