#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

struct noArvore {
    struct noArvore* ponteiroEsquerda;
    int dado;
    struct noArvore* ponteiroDireita;
};

void inserirNo(struct noArvore** ponteiroPonteiroArvore, int valor) {
    if (*ponteiroPonteiroArvore == nullptr) {
        *ponteiroPonteiroArvore = new struct noArvore;

        if (*ponteiroPonteiroArvore != nullptr) {
            (*ponteiroPonteiroArvore)->dado = valor;
            (*ponteiroPonteiroArvore)->ponteiroEsquerda = nullptr;
            (*ponteiroPonteiroArvore)->ponteiroDireita = nullptr;
        } else
            std::cout << "\n" << valor << " nao inserido. Nao ha memoria disponivel.\n";
    } else {
        if (valor < (*ponteiroPonteiroArvore)->dado)
            inserirNo(&((*ponteiroPonteiroArvore)->ponteiroEsquerda), valor);
        else
            inserirNo(&((*ponteiroPonteiroArvore)->ponteiroDireita), valor);
    }
}

void preOrdem(struct noArvore* ponteiroArvore, bool raiz = true) {
    if (ponteiroArvore != nullptr) {
        if (raiz)
            std::cout << "[" << ponteiroArvore->dado << "] ";
        else
            std::cout << ponteiroArvore->dado << " ";

        preOrdem(ponteiroArvore->ponteiroEsquerda, false);
        preOrdem(ponteiroArvore->ponteiroDireita, false);
    }
}

void ordem(struct noArvore* ponteiroArvore, bool raiz = true) {
    if (ponteiroArvore != nullptr) {
        ordem(ponteiroArvore->ponteiroEsquerda, false);
        
        if (raiz)
            std::cout << "[" << ponteiroArvore->dado << "] ";
        else
            std::cout << ponteiroArvore->dado << " ";

        ordem(ponteiroArvore->ponteiroDireita, false);
    }
}

void posOrdem(struct noArvore* ponteiroArvore, bool raiz = true) {
    if (ponteiroArvore != nullptr) {
        posOrdem(ponteiroArvore->ponteiroEsquerda, false);
        posOrdem(ponteiroArvore->ponteiroDireita, false);

        if (raiz)
            std::cout << "[" << ponteiroArvore->dado << "]";
        else
            std::cout << ponteiroArvore->dado << " ";
    }
}

int main() {
    struct noArvore* ponteiroRaiz = nullptr;

    std::srand(std::time(nullptr));
    std::vector<int> numeros;

    while (numeros.size() < 10) {
        int numero = std::rand() % 100;

        if (std::find(numeros.begin(), numeros.end(), numero) == numeros.end())
            numeros.push_back(numero);
    }

    std::cout << "\nOs numeros que serao inseridos na arvore sao: (a raiz esta destacada entre colchetes)\n";

    inserirNo(&ponteiroRaiz, numeros[0]);
    std::cout << "[" << numeros[0] << "] ";

    for (int i = 1; i < numeros.size(); i++) {
        inserirNo(&ponteiroRaiz, numeros[i]);
        std::cout << numeros[i] << " ";
    }

    std::cout << "\n\nTravessia pre-ordem:\n";
    preOrdem(ponteiroRaiz);

    std::cout << "\n\nTravessia ordem:\n";
    ordem(ponteiroRaiz);

    std::cout << "\n\nTravessia pos-ordem:\n";
    posOrdem(ponteiroRaiz);

    std::cout << "\n";

    return 0;
}
