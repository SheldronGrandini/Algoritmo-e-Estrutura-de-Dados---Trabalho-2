#include "Deque.h"
#include <iostream>
using namespace std;

// Construtor: a lista encadeada circular já se inicializa vazia
Deque::Deque() {}

// Destrutor: a memória dos nós é gerenciada pelo destrutor de ListaDuplamenteEncadeadaCircular
Deque::~Deque() {}

// Insere um elemento no início do deque
// Complexidade: O(1) - utiliza InserirNoInicio da lista circular (religa apenas os ponteiros ant/prox)
bool Deque::InserirNoInicio(Elemento* elemento) {
    if (elemento == nullptr) {
        return false;
    }
    return this -> lista.InserirNoInicio(elemento);
}

// Insere um elemento no final do deque
// Complexidade: O(1) - utiliza InserirNoFim da lista circular (insere antes do início e atualiza inicio->ant)
bool Deque::InserirNoFinal(Elemento* elemento) {
    if (elemento == nullptr) {
        return false;
    }
    return this -> lista.InserirNoFim(elemento);
}

// Remove e devolve o elemento do início do deque
// Complexidade: O(1) - desliga o nó do início, religa o novo início e apaga o nó
Elemento* Deque::RemoverInicio() {
    return this -> lista.RemoverPrimeiro();
}

// Remove e devolve o elemento do final do deque
// Complexidade: O(1) - o último nó é inicio->ant, acessado diretamente
Elemento* Deque::RemoverFinal() {
    return this -> lista.RemoverUltimo();
}

// Consulta o elemento do início do deque sem removê-lo
// Complexidade: O(1) - acesso direto ao nó inicial
Elemento* Deque::ConsultarInicio() const {
    return this -> lista.GetPrimeiro();
}

// Consulta o elemento do final do deque sem removê-lo
// Complexidade: O(1) - acesso direto ao nó inicial->ant
Elemento* Deque::ConsultarFinal() const {
    return this -> lista.GetUltimo();
}

// Verifica se o deque está vazio
// Complexidade: O(1) - delega para o método Vazia() da lista subjacente
bool Deque::Vazia() const {
    return this -> lista.Vazia();
}

// Retorna a quantidade de elementos presentes no deque
// Complexidade: O(1) - delega para o GetTamanho() da lista subjacente
int Deque::GetTamanho() const {
    return this -> lista.GetTamanho();
}

// Exibe os elementos do deque do início até o final
// Complexidade: O(n) - percorre a lista circular chamando a impressão de cada elemento
void Deque::Imprimir() const {
    if (Vazia()) {
        cout << "Deque vazio." << endl;
        return;
    }
    cout << "--- Elementos no Deque (Início até o Final) ---" << endl;
    this -> lista.Imprimir();
}
