#include "FilaEncadeada.h"
#include <iostream>
using namespace std;

// Construtor: inicializa a fila encadeada com uma capacidade máxima definida
FilaEncadeada::FilaEncadeada(int capacidadeMaxima) {
    this -> capacidadeMaxima = capacidadeMaxima;
}

// Destrutor: a memória dos nós é gerenciada pelo destrutor de ListaSimplesmenteEncadeada
FilaEncadeada::~FilaEncadeada() {}

// Insere um novo elemento no final da fila
// Complexidade: O(1) - utiliza InserirNoFim da lista encadeada (religa apenas o ponteiro do fim)
bool FilaEncadeada::Enfileirar(Elemento* elemento) {
    if (elemento == nullptr || FilaCheia()) {
        return false;
    }
    return this -> lista.InserirNoFim(elemento);
}

// Remove o primeiro elemento da fila (início)
// Complexidade: O(1) - CORRECAO DA INEFICIENCIA DA FILA SEQUENCIAL:
// Na fila sequencial, RemoverPrimeiro custava O(n) porque todos os elementos
// tinham de ser deslocados uma posição para a esquerda. Aqui nada e deslocado:
// apenas o nó do início é desligado e apagado, logo o custo é O(1) estrito.
bool FilaEncadeada::Desenfileirar() {
    if (FilaVazia()) {
        return false;
    }
    this -> lista.RemoverPrimeiro();
    return true;
}

// Consulta o elemento situado na frente da fila sem removê-lo
// Complexidade: O(1) - acesso direto ao primeiro nó da lista encadeada
Elemento* FilaEncadeada::ConsultarFrente() const {
    if (FilaVazia()) {
        return nullptr;
    }
    return this -> lista.GetPrimeiro();
}

// Verifica se a fila está vazia
// Complexidade: O(1) - delega para o método Vazia() da lista encadeada
bool FilaEncadeada::FilaVazia() const {
    return this -> lista.Vazia();
}

// Verifica se a fila atingiu a capacidade máxima estipulada
// Complexidade: O(1) - comparação direta entre o tamanho atual da lista e a capacidade máxima
bool FilaEncadeada::FilaCheia() const {
    return this -> lista.GetTamanho() >= this -> capacidadeMaxima;
}

// Retorna a quantidade de elementos atualmente na fila
// Complexidade: O(1) - delega para o GetTamanho() da lista subjacente
int FilaEncadeada::GetTamanho() const {
    return this -> lista.GetTamanho();
}

// Exibe os elementos da fila do início até o fim
// Complexidade: O(n) - percorre os elementos chamando a impressão sequencial
void FilaEncadeada::Imprimir() const {
    if (FilaVazia()) {
        cout << "Fila encadeada vazia." << endl;
        return;
    }
    cout << "--- Elementos na Fila Encadeada (Inicio até o Fim) ---" << endl;
    this -> lista.Imprimir();
}
