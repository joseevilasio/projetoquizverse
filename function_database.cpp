#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>

#ifdef _WIN32
    // Inclua as bibliotecas específicas do Windows aqui
    #include <canio.h>   
#elif __linux__
    // Inclua as bibliotecas específicas do Linux aqui
    #include <termios.h>    

#endif

#ifndef FUNCTION_DATABASE_H
#define FUNCTION_DATABASE_H

using namespace std;

void eliminarLinhaArquivo(const string& nomeArquivo, int linhaParaEliminar) {
    ifstream arquivoEntrada(nomeArquivo);
    ofstream arquivoTemporario("assets/temp.txt");

    string linha;
    int numeroLinha = 1;

    while (getline(arquivoEntrada, linha)) {
        if (numeroLinha != linhaParaEliminar) {
            arquivoTemporario << linha << endl;
        }
        numeroLinha++;
    }

    arquivoEntrada.close();
    arquivoTemporario.close();

    remove(nomeArquivo.c_str());
    rename("assets/temp.txt", nomeArquivo.c_str());
}

int consultarLinhadeArquivo(string userEmail){
    //Recebe email e identifica em qual linha consta os dados e retornar o valor em int
    ifstream arquivo("assets/database.txt");  // Abre o arquivo para leitura
    int contarLinha = 0;
    
    if (arquivo.is_open()){
        string linha;

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;

            contarLinha += 1;

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }
                
            if (userEmail == dados[1]){
                return contarLinha;
                break;  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return 0;
}

string buscarLinhadeArquivo(string userEmail){
    //Recebe email e identifica em qual linha consta os dados e retornar o valor em int
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
                return linha;
                break;  
            }
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }
    return "";
}

void modificarPontos(string userEmail, int pontosUser) {

    string nomeArquivo = "assets/database.txt";

    ifstream arquivoEntrada(nomeArquivo);
    ofstream arquivoTemporario("temp.txt");

    string linha;
    int numeroLinha = 1;
    int linhaParaEliminar = consultarLinhadeArquivo(userEmail);

    while (getline(arquivoEntrada, linha)) {
        if (numeroLinha != linhaParaEliminar) {
            arquivoTemporario << linha << endl;
        }
        numeroLinha++;
    }

    istringstream iss(buscarLinhadeArquivo(userEmail));
    string dado;
    vector<string> dados; 

    while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }
    

    arquivoTemporario << dados[0] << "," << dados[1] << "," << dados[2] << "," << dados[3] << "," << dados[4] << "," << pontosUser << endl;

    arquivoEntrada.close();
    arquivoTemporario.close();

    remove(nomeArquivo.c_str());
    rename("temp.txt", nomeArquivo.c_str());
}



#endif
