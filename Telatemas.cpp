#
#include <iostream>

int main() {
    int opcao;

    std::cout << "Bem-vindo(a) ao programa de seleção de temas!" << std::endl;
    std::cout << "Escolha um tema:" << std::endl;
    std::cout << "1. Tema Geografia e Cultura " << std::endl;
    std::cout << "2. Tema Fisica e Matemática" << std::endl;
    std::cout << "3. Tema Química e Biologia" << std::endl;

    std::cout << "Digite o número da opção desejada: ";
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            // Lógica para definir o tema claro
            std::cout << "Tema claro selecionado." << std::endl;
            break;
        case 2:
            // Lógica para definir o tema escuro
            std::cout << "Tema escuro selecionado." << std::endl;
            break;
        case 3:
            // Lógica para definir o tema colorido
            std::cout << "Tema colorido selecionado." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            return 0;
    }

    std::cout << std::endl;
    std::cout << "Agora vamos responder algumas perguntas:" << std::endl;

    int resposta1, resposta2, resposta3;

    std::cout << "1. " << std::endl;
    std::cout << "a) " << std::endl;
    std::cout << "b) " << std::endl;
    std::cout << "c) " << std::endl;
    std::cout << "d) " << std::endl;
    std::cout << "Digite a letra correspondente à resposta: ";
    std::cin >> resposta1;

    std::cout << std::endl;

    std::cout << "2. Qual é a capital da França?" << std::endl;
    std::cout << "a) Paris" << std::endl;
    std::cout << "b) Londres" << std::endl;
    std::cout << "c) Roma" << std::endl;
    std::cout << "d) Berlim" << std::endl;
    std::cout << "Digite a letra correspondente à resposta: ";
    std::cin >> resposta2;

    std::cout << std::endl;

    std::cout << "3. Qual é a fórmula da energia cinética?" << std::endl;
    std::cout << "a) E = mc²" << std::endl;
    std::cout << "b) E = mgh" << std::endl;
    std::cout << "c) E = 1/2mv²" << std::endl;
    std::cout << "d) E = Fd" << std::endl;
    std::cout << "Digite a letra correspondente à resposta: ";
    std::cin >> resposta3;

    std::cout << std::endl;

    // Lógica para verificar as respostas e exibir o resultado
    int pontos = 0;

    if (resposta1 == 2) {
        pontos++;
    }
    return 0;}

