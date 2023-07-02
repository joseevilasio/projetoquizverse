#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <filesystem>
#ifndef FUNCTION_DATABASE_H
#define FUNCTION_DATABASE_H


using namespace std;
namespace fs = filesystem;

struct Usuario {
    // struct para armazenar os dados do usuário
    string nomeCompleto, email, password, pergunta, resposta;
    int pontos;
    };

struct Perguntas {
    // struct para armazenar os dados de perguntas
        string tema, pergunta, respostaA, respostaB, respostaC, respostaD, respostaCorreta;
    };

string path(string nomeArquivo) {
    //Recebe um nome de arquivo que está na pasta assets    

    fs::path caminhoAbsoluto = fs::current_path() / "assets" / nomeArquivo;
    fs::path caminhoRelativo = fs::relative(caminhoAbsoluto);

    #ifdef _WIN32
        return caminhoAbsoluto.string();
    #elif defined __unix__
        return caminhoRelativo;
    #endif
}

vector<Perguntas> databasePerguntas (string nomeArquivo) {
    // Recebe path e retorna um vector com as structs
    Perguntas questao; // instancia da struct
    vector<Perguntas> questoes; //Recebe as structs
    string _respostaCorreta; // string para receber resposta sem espaço

    ifstream arquivo(path(nomeArquivo)); // recebe de acordo com tema e dificuldade escolhida o path do arquivo de perguntas    
    
    if (arquivo.is_open()){
        string linha;        

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;            

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }

            questao.tema = dados[0];
            questao.pergunta = dados[1];
            questao.respostaA = dados[2];
            questao.respostaB = dados[3];
            questao.respostaC = dados[4];
            questao.respostaD = dados[5];
            //Lidar com espaços em brancos gerados no getline
            _respostaCorreta.clear();
            for (size_t i = 0; i < (dados[6].size() - 1) ; i++) {
                _respostaCorreta.push_back(dados[6][i]);
            }
            questao.respostaCorreta = _respostaCorreta;
            questoes.push_back(questao);
        }

        arquivo.close();

    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }

    return questoes;
}

vector<Usuario> databaseUsuarios () {
    // Recebe path e retorna um vector com as structs
    Usuario usuario; // instancia da struct
    vector<Usuario> usuarios; //Recebe as structs

    ifstream arquivo(path("database.txt"));
    
    if (arquivo.is_open()){
        string linha;        

        while (getline(arquivo, linha)) {
            istringstream iss(linha);
            string dado;
            vector<string> dados;            

            while (getline(iss, dado, ',')) {
                dados.push_back(dado); //A cada volta no loop dentro da linha recebe o valor separado por vírgula                
            }

            usuario.nomeCompleto = dados[0];
            usuario.email = dados[1];
            usuario.password = dados[2];
            usuario.pergunta = dados[3];
            usuario.resposta = dados[4];
            usuario.pontos = stoi(dados[5]);

            usuarios.push_back(usuario);
        }

        arquivo.close();

    } else {
        cout << "Falha ao abrir o arquivo." << endl;
    }

    return usuarios;
}

void eliminarDados(string userEmail) {
    // Recebe argumentos para eliminar linha do arquivo

    string _nomeArquivo = "assets/database.txt";    
    ofstream arquivoTemporario("temp.txt");    

    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail != usuario.email){
            
            arquivoTemporario << usuario.nomeCompleto << "," << usuario.email << "," << usuario.password;
            arquivoTemporario << "," << usuario.pergunta << "," << usuario.resposta <<  "," << usuario.pontos << endl;            
        }
    }
    
    arquivoTemporario.close();

    remove(_nomeArquivo.c_str());
    rename("temp.txt", _nomeArquivo.c_str());
}

void modificarPontos(string userEmail, int pontosUser) {
    
    string _nomeArquivo = "assets/database.txt";    
    ofstream arquivoTemporario("temp.txt");    

    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail != usuario.email){
            
            arquivoTemporario << usuario.nomeCompleto << "," << usuario.email << "," << usuario.password;
            arquivoTemporario << "," << usuario.pergunta << "," << usuario.resposta <<  "," << usuario.pontos << endl;
            
        }
    }

    for(const auto& usuario : databaseUsuarios()) {          
        if (userEmail == usuario.email){
            
            arquivoTemporario << usuario.nomeCompleto << "," << usuario.email << "," << usuario.password;
            arquivoTemporario << "," << usuario.pergunta << "," << usuario.resposta <<  "," << pontosUser << endl;
            break;
        }
    }
    
    arquivoTemporario.close();

    remove(_nomeArquivo.c_str());
    rename("temp.txt", _nomeArquivo.c_str());
}

#endif
