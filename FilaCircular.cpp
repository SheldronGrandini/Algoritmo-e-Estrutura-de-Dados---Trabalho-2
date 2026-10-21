#include "FilaCircular.h"
#include <iostream>
using namespace std;

// Construtor: aloca o vetor de ponteiros circular e inicializa os índices de controle
// Complexidade: O(capacidade) - aloca o vetor de ponteiros com a capacidade informada.
FilaCircular::FilaCircular(int capacidade) {
    this -> capacidade = (capacidade > 0) ? capacidade : 10;
    this -> inicio = 0;
    this -> tamanho = 0;
    this -> elementos = new Elemento*[this -> capacidade];
}

// Destrutor: desaloca o vetor de ponteiros da memória
// Os objetos Elemento continuam sob responsabilidade de quem os instanciou (conforme README da Parte 2)
// Complexidade: O(1) - desaloca o vetor de ponteiros (os objetos Elemento são de responsabilidade de quem os instanciou).
FilaCircular::~FilaCircular() {
    delete[] this -> elementos;
}

// Insere um elemento no final da fila circular
// Complexidade: O(1) - calcula a posição final através da fórmula (inicio + tamanho) % capacidade
// sem necessidade de percorrer ou deslocar nada
bool FilaCircular::Enfileirar(Elemento* elemento) {
    if (elemento == nullptr || FilaCheia()) {
        return false;
    }

    int fim = (this -> inicio + this -> tamanho) % this -> capacidade;
    this -> elementos[fim] = elemento;
    this -> tamanho++;

    return true;
}

// Remove o primeiro elemento da fila circular
// Complexidade: O(1) - CORREÇÃO DA INEFICIÊNCIA:
// Em vez de deslocar todos os elementos para a esquerda (que custava O(n)),
// apenas avançamos o índice 'inicio' de forma circular usando módulo. Tempo estritamente constante!
bool FilaCircular::Desenfileirar() {
    if (FilaVazia()) {
        return false;
    }

    this -> inicio = (this -> inicio + 1) % this -> capacidade;
    this -> tamanho--;

    return true;
}

// Consulta o elemento situado na frente da fila circular
// Complexidade: O(1) - acesso direto pelo índice 'inicio' no vetor
Elemento* FilaCircular::ConsultarFrente() const {
    if (FilaVazia()) {
        return nullptr;
    }
    return this -> elementos[this -> inicio];
}

// Verifica se a fila circular está vazia
// Complexidade: O(1) - verificação direta do contador de tamanho
bool FilaCircular::FilaVazia() const {
    return this -> tamanho == 0;
}

// Verifica se a fila circular atingiu a sua capacidade máxima
// Complexidade: O(1) - comparação entre o tamanho atual e a capacidade alocada
bool FilaCircular::FilaCheia() const {
    return this -> tamanho == this -> capacidade;
}

// Retorna a quantidade de elementos presentes na fila
// Complexidade: O(1) - retorno direto da variável tamanho
int FilaCircular::GetTamanho() const {
    return this -> tamanho;
}

// Retorna a capacidade total de armazenamento do vetor circular
// Complexidade: O(1) - retorno direto da variável capacidade
int FilaCircular::GetCapacidade() const {
    return this -> capacidade;
}

// Imprime os elementos na ordem lógica da fila (da frente até o final)
// Complexidade: O(n) - percorre os n elementos respeitando a aritmética modular
void FilaCircular::Imprimir() const {
    if (FilaVazia()) {
        cout << "Fila circular vazia." << endl;
        return;
    }

    cout << "--- Elementos na Fila Circular (Frente ate o Fim) ---" << endl;
    for (int i = 0; i < this -> tamanho; i++) {
        int pos = (this -> inicio + i) % this -> capacidade;
        this -> elementos[pos] -> ImprimirInfo();
    }
}
