#include "ListaNaoOrdenada.h"
#include <iostream>

using namespace std;

// Complexidade: O(1) - aloca o vetor inicial de ponteiros com capacidade 10.
ListaNaoOrdenada::ListaNaoOrdenada() {
    capacidade = 10;
    tamanho = 0;
    elementos = new Elemento*[capacidade];
}

// Complexidade: O(1) - libera apenas o vetor de ponteiros (os objetos Elemento são de responsabilidade de quem os instanciou).
ListaNaoOrdenada::~ListaNaoOrdenada() {
    delete[] elementos;
}

// Complexidade: O(n) - cópia os n ponteiros para o novo vetor. Dobrar a capacidade torna a inserção O(1) amortizado.
void ListaNaoOrdenada::AumentarCapacidade() {
    capacidade *= 2;
    Elemento** novosElementos = new Elemento*[capacidade];
    for (int i = 0; i < tamanho; i++) novosElementos[i] = elementos[i];
    delete[] elementos;
    elementos = novosElementos;
}

// Complexidade: O(n) - busca de duplicidade O(n) + deslocamento de n elementos para a direita.
bool ListaNaoOrdenada::InserirNoInicio(Elemento* elemento) {
    if (elemento == nullptr || BuscarPeloId(elemento->GetId()) != nullptr) return false;
    if (tamanho == capacidade) AumentarCapacidade();
    for (int i = tamanho; i > 0; i--) elementos[i] = elementos[i - 1];
    elementos[0] = elemento;
    tamanho++;
    return true;
}

// Complexidade: O(1) amortizado (pior caso O(n)) - insere no fim sem deslocar, mas a busca de duplicidade custa O(n).
bool ListaNaoOrdenada::InserirNoFinal(Elemento* elemento) {
    if (elemento == nullptr || BuscarPeloId(elemento->GetId()) != nullptr) return false;
    if (tamanho == capacidade) AumentarCapacidade();
    elementos[tamanho++] = elemento;
    return true;
}

// Complexidade: O(n) - desloca os n-1 elementos restantes uma posição para a esquerda.
void ListaNaoOrdenada::RemoverPrimeiro() {
    if (Vazia()) return;
    for (int i = 0; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
    tamanho--;
}

// Complexidade: O(1) - apenas decrementa o tamanho lógico, não há deslocamento.
void ListaNaoOrdenada::RemoverUltimo() {
    if (Vazia()) return;
    tamanho--;
}

// Complexidade: O(n) - busca linear pelo ID + deslocamento dos elementos posteriores.
bool ListaNaoOrdenada::RemoverPeloId(int id) {
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i]->GetId() == id) {
            for (int j = i; j < tamanho - 1; j++) elementos[j] = elementos[j + 1];
            tamanho--;
            return true;
        }
    }
    return false;
}

// Complexidade: O(n) - busca linear, percorre todos os elementos.
Elemento* ListaNaoOrdenada::BuscarPeloId(int id) const {
    for (int i = 0; i < tamanho; i++)
        if (elementos[i]->GetId() == id) return elementos[i];
    return nullptr;
}

// Complexidade: O(n) - busca linear pelo ID a ser alterado.
bool ListaNaoOrdenada::AlterarPeloId(int id, Elemento* novoElemento) {
    if (novoElemento == nullptr || novoElemento->GetId() != id) return false;
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i]->GetId() == id) {
            elementos[i] = novoElemento;
            return true;
        }
    }
    return false;
}

// Complexidade: O(1) - retorna o contador mantido em memória.
int ListaNaoOrdenada::GetTamanho() const { return tamanho; }
// Complexidade: O(1) - comparação do contador com zero.
bool ListaNaoOrdenada::Vazia() const { return tamanho == 0; }

// Complexidade: O(1) - acesso direto ao primeiro elemento do vetor.
Elemento* ListaNaoOrdenada::GetPrimeiro() const {
    if (Vazia()) return nullptr;
    return elementos[0];
}

// Complexidade: O(1) - acesso direto ao último elemento do vetor.
Elemento* ListaNaoOrdenada::GetUltimo() const {
    if (Vazia()) return nullptr;
    return elementos[tamanho - 1];
}

// Complexidade: O(n) - percorre todos os elementos chamando ImprimirInfo (o custo real inclui a saída de tela).
void ListaNaoOrdenada::Imprimir() const {
    for (int i = 0; i < tamanho; i++){ 
        elementos[i]->ImprimirInfo();
        cout << endl;
    }
}
