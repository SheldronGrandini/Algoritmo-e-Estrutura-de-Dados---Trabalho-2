#include "Pilha.h"
#include <iostream>
using namespace std;

// Construtor: inicializa a pilha definindo sua capacidade limite
Pilha::Pilha(int capacidadeMaxima) {
    this -> capacidadeMaxima = capacidadeMaxima;
}

// Destrutor: a memória da lista interna é gerenciada pelo destrutor de ListaNaoOrdenada
Pilha::~Pilha() {}

// Insere um novo elemento no topo da pilha
// Complexidade: O(1) - utiliza InserirNoFinal da ListaNaoOrdenada (sem deslocamento de elementos)
bool Pilha::Empilhar(Elemento* elemento) {
    if (elemento == nullptr || PilhaCheia()) {
        return false;
    }
    return this -> lista.InserirNoFinal(elemento);
}

// Remove o elemento do topo da pilha
// Complexidade: O(1) - utiliza RemoverUltimo da ListaNaoOrdenada (apenas decrementa o tamanho lógico)
bool Pilha::Desempilhar() {
    if (PilhaVazia()) {
        return false;
    }
    this -> lista.RemoverUltimo();
    return true;
}

// Consulta o elemento situado no topo da pilha sem removê-lo
// Complexidade: O(1) - acesso direto ao último elemento da lista através do GetUltimo()
Elemento* Pilha::ConsultarTopo() const {
    if (PilhaVazia()) {
        return nullptr;
    }
    return this -> lista.GetUltimo();
}

// Verifica se a pilha está vazia
// Complexidade: O(1) - delega para o método Vazia() da lista subjacente
bool Pilha::PilhaVazia() const {
    return this -> lista.Vazia();
}

// Verifica se a pilha atingiu seu limite máximo de elementos
// Complexidade: O(1) - comparação direta entre o tamanho atual da lista e a capacidade máxima
bool Pilha::PilhaCheia() const {
    return this -> lista.GetTamanho() >= this -> capacidadeMaxima;
}

// Retorna o total de elementos empilhados atualmente
// Complexidade: O(1) - delega para o GetTamanho() da lista subjacente
int Pilha::GetTamanho() const {
    return this -> lista.GetTamanho();
}

// Exibe os elementos da pilha (base até o topo)
// Complexidade: O(n) - delega para a impressão sequencial da lista
void Pilha::Imprimir() const {
    if (PilhaVazia()) {
        cout << "Pilha vazia." << endl;
        return;
    }
    cout << "--- Elementos na Pilha (Base ate o Topo) ---" << endl;
    this -> lista.Imprimir();
}
