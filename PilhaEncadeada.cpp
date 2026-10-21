#include "PilhaEncadeada.h"
#include <iostream>
using namespace std;

// Construtor: inicializa a pilha definindo sua capacidade limite
PilhaEncadeada::PilhaEncadeada(int capacidadeMaxima) {
    this -> capacidadeMaxima = capacidadeMaxima;
}

// Destrutor: a memória dos nós é gerenciada pelo destrutor de ListaSimplesmenteEncadeada
PilhaEncadeada::~PilhaEncadeada() {}

// Insere um novo elemento no topo da pilha
// Complexidade: O(1) - utiliza InserirNoInicio da lista encadeada (cria o nó e religa o ponteiro)
bool PilhaEncadeada::Empilhar(Elemento* elemento) {
    if (elemento == nullptr || PilhaCheia()) {
        return false;
    }
    return this -> lista.InserirNoInicio(elemento);
}

// Remove o elemento do topo da pilha
// Complexidade: O(1) - utiliza RemoverPrimeiro da lista encadeada (apenas desliga e apaga o nó)
bool PilhaEncadeada::Desempilhar() {
    if (PilhaVazia()) {
        return false;
    }
    this -> lista.RemoverPrimeiro();
    return true;
}

// Consulta o elemento situado no topo da pilha sem removê-lo
// Complexidade: O(1) - acesso direto ao primeiro nó da lista encadeada
Elemento* PilhaEncadeada::ConsultarTopo() const {
    if (PilhaVazia()) {
        return nullptr;
    }
    return this -> lista.GetPrimeiro();
}

// Verifica se a pilha está vazia
// Complexidade: O(1) - delega para o método Vazia() da lista subjacente
bool PilhaEncadeada::PilhaVazia() const {
    return this -> lista.Vazia();
}

// Verifica se a pilha atingiu seu limite máximo de elementos
// Complexidade: O(1) - comparação direta entre o tamanho atual da lista e a capacidade máxima
bool PilhaEncadeada::PilhaCheia() const {
    return this -> lista.GetTamanho() >= this -> capacidadeMaxima;
}

// Retorna o total de elementos empilhados atualmente
// Complexidade: O(1) - delega para o GetTamanho() da lista subjacente
int PilhaEncadeada::GetTamanho() const {
    return this -> lista.GetTamanho();
}

// Exibe os elementos da pilha (base até o topo)
// Complexidade: O(n) - delega para a impressão sequencial da lista encadeada
void PilhaEncadeada::Imprimir() const {
    if (PilhaVazia()) {
        cout << "Pilha encadeada vazia." << endl;
        return;
    }
    cout << "--- Elementos na Pilha Encadeada (Base até o Topo) ---" << endl;
    this -> lista.Imprimir();
}
