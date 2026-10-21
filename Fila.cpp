#include "Fila.h"
#include <iostream>
using namespace std;

// Construtor: inicializa a fila sequencial com uma capacidade máxima definida
// Complexidade: O(1) - define apenas o limite de capacidade da fila.
Fila::Fila(int capacidadeMaxima) {
    this -> capacidadeMaxima = capacidadeMaxima;
}

// Destrutor: a memória do vetor interno é gerenciada pela própria ListaNaoOrdenada
// Complexidade: O(1) - a memória do vetor interno é gerenciada pela própria ListaNaoOrdenada.
Fila::~Fila() {}

// Insere um novo elemento no final da fila
// Complexidade: O(1) - utiliza InserirNoFinal da lista sequencial, inserindo no fim sem deslocamento
bool Fila::Enfileirar(Elemento* elemento) {
    if (elemento == nullptr || FilaCheia()) {
        return false;
    }
    return this -> lista.InserirNoFinal(elemento);
}

// Remove o primeiro elemento da fila (início)
// Complexidade: O(n) - INEFICIÊNCIA IDENTIFICADA:
// Como utiliza RemoverPrimeiro() da lista sequencial, todos os (n - 1) elementos restantes
// precisam ser deslocados uma posição para a esquerda na memória. Por isso propomos a FilaCircular!
bool Fila::Desenfileirar() {
    if (FilaVazia()) {
        return false;
    }
    this -> lista.RemoverPrimeiro();
    return true;
}

// Consulta o elemento situado na frente da fila sem removê-lo
// Complexidade: O(1) - acesso direto ao primeiro elemento através do GetPrimeiro()
Elemento* Fila::ConsultarFrente() const {
    if (FilaVazia()) {
        return nullptr;
    }
    return this -> lista.GetPrimeiro();
}

// Verifica se a fila está vazia
// Complexidade: O(1) - consulta direta ao método Vazia() da lista
bool Fila::FilaVazia() const {
    return this -> lista.Vazia();
}

// Verifica se a fila atingiu a capacidade máxima estipulada
// Complexidade: O(1) - compara o tamanho atual da lista com a capacidade máxima
bool Fila::FilaCheia() const {
    return this -> lista.GetTamanho() >= this -> capacidadeMaxima;
}

// Retorna a quantidade de elementos atualmente na fila
// Complexidade: O(1) - retorna o tamanho da lista subjacente
int Fila::GetTamanho() const {
    return this -> lista.GetTamanho();
}

// Exibe os elementos da fila do início até o fim
// Complexidade: O(n) - percorre os elementos chamando a impressão sequencial
void Fila::Imprimir() const {
    if (FilaVazia()) {
        cout << "Fila vazia." << endl;
        return;
    }
    cout << "--- Elementos na Fila (Inicio ate o Fim) ---" << endl;
    this -> lista.Imprimir();
}
