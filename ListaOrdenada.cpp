#include "ListaOrdenada.h"
#include <iostream>

using namespace std;

// Complexidade: O(1) - aloca o vetor inicial de ponteiros com capacidade 10.
ListaOrdenada::ListaOrdenada() {
    capacidade = 10;
    tamanho = 0;
    elementos = new Elemento*[capacidade];
}

// Complexidade: O(1) - libera apenas o vetor de ponteiros (os objetos Elemento são de responsabilidade de quem os instanciou).
ListaOrdenada::~ListaOrdenada() {
    delete[] elementos;
}

// Complexidade: O(n) - cópia os n ponteiros para o novo vetor. Dobrar a capacidade torna a inserção O(1) amortizado.
void ListaOrdenada::AumentarCapacidade() {
    capacidade *= 2;
    Elemento** novosElementos = new Elemento*[capacidade];
    for (int i = 0; i < tamanho; i++) novosElementos[i] = elementos[i];
    delete[] elementos;
    elementos = novosElementos;
}

// Complexidade: O(log n) - busca binária: a cada passo o intervalo de busca é reduzido a metade.
int ListaOrdenada::EncontrarPosicao(int id) const {
    int inicio = 0, fim = tamanho;
    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (elementos[meio]->GetId() < id) inicio = meio + 1;
        else fim = meio;
    }
    return inicio;
}

// O(n): encontra a posicao por busca binaria, mas desloca elementos para abrir espaco.
bool ListaOrdenada::InserirNoInicio(Elemento* elemento) {
    if (elemento == nullptr) return false;
    int posicao = EncontrarPosicao(elemento->GetId());
    if (posicao < tamanho && elementos[posicao]->GetId() == elemento->GetId()) return false;
    if (tamanho == capacidade) AumentarCapacidade();
    for (int i = tamanho; i > posicao; i--) elementos[i] = elementos[i - 1];
    elementos[posicao] = elemento;
    tamanho++;
    return true;
}

// Mantem a ordem por ID, mesmo que o metodo seja chamado para inserir "no final".
// Complexidade: O(n) - delega para InserirNoInicio, pois a ordem por ID deve ser mantida.
bool ListaOrdenada::InserirNoFinal(Elemento* elemento) {
    return InserirNoInicio(elemento);
}

// O(n): desloca os elementos restantes.
void ListaOrdenada::RemoverPrimeiro() {
    if (Vazia()) return;
    for (int i = 0; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
    tamanho--;
}

// O(1): diminui o tamanho logico da lista.
void ListaOrdenada::RemoverUltimo() {
    if (Vazia()) return;
    tamanho--;
}

// Complexidade: O(n) - O(log n) para achar a posição + O(n) para deslocar os elementos posteriores.
bool ListaOrdenada::RemoverPeloId(int id) {
    int posicao = EncontrarPosicao(id);
    if (posicao == tamanho || elementos[posicao]->GetId() != id) return false;
    for (int i = posicao; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
    tamanho--;
    return true;
}

// Complexidade: O(log n) - busca binária sobre o ID.
Elemento* ListaOrdenada::BuscarPeloId(int id) const {
    int posicao = EncontrarPosicao(id);
    if (posicao < tamanho && elementos[posicao]->GetId() == id) return elementos[posicao];
    return nullptr;
}

// Complexidade: O(log n) - busca binária sobre o ID.
bool ListaOrdenada::AlterarPeloId(int id, Elemento* novoElemento) {
    if (novoElemento == nullptr || novoElemento->GetId() != id) return false;
    int posicao = EncontrarPosicao(id);
    if (posicao == tamanho || elementos[posicao]->GetId() != id) return false;
    elementos[posicao] = novoElemento;
    return true;
}

// Complexidade: O(1) - retorna o contador mantido em memória.
int ListaOrdenada::GetTamanho() const { return tamanho; }
// Complexidade: O(1) - comparação do contador com zero.
bool ListaOrdenada::Vazia() const { return tamanho == 0; }

// Complexidade: O(n) - percorre todos os elementos em ordem crescente de ID (o custo real inclui a saída de tela).
void ListaOrdenada::Imprimir() const {
    for (int i = 0; i < tamanho; i++){
        elementos[i]->ImprimirInfo();
        cout << endl;
    } 
}
