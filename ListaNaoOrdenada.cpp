#include "ListaNaoOrdenada.h"
#include <iostream>

using namespace std;

ListaNaoOrdenada::ListaNaoOrdenada() {
    capacidade = 10;
    tamanho = 0;
    elementos = new Elemento*[capacidade];
}

ListaNaoOrdenada::~ListaNaoOrdenada() {
    delete[] elementos;
}

void ListaNaoOrdenada::AumentarCapacidade() {
    capacidade *= 2;
    Elemento** novosElementos = new Elemento*[capacidade];
    for (int i = 0; i < tamanho; i++) novosElementos[i] = elementos[i];
    delete[] elementos;
    elementos = novosElementos;
}

bool ListaNaoOrdenada::InserirNoInicio(Elemento* elemento) {
    if (elemento == nullptr || BuscarPeloId(elemento->GetId()) != nullptr) return false;
    if (tamanho == capacidade) AumentarCapacidade();
    for (int i = tamanho; i > 0; i--) elementos[i] = elementos[i - 1];
    elementos[0] = elemento;
    tamanho++;
    return true;
}

bool ListaNaoOrdenada::InserirNoFinal(Elemento* elemento) {
    if (elemento == nullptr || BuscarPeloId(elemento->GetId()) != nullptr) return false;
    if (tamanho == capacidade) AumentarCapacidade();
    elementos[tamanho++] = elemento;
    return true;
}

void ListaNaoOrdenada::RemoverPrimeiro() {
    if (Vazia()) return;
    for (int i = 0; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
    tamanho--;
}

void ListaNaoOrdenada::RemoverUltimo() {
    if (Vazia()) return;
    tamanho--;
}

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

Elemento* ListaNaoOrdenada::BuscarPeloId(int id) const {
    for (int i = 0; i < tamanho; i++)
        if (elementos[i]->GetId() == id) return elementos[i];
    return nullptr;
}

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

int ListaNaoOrdenada::GetTamanho() const { return tamanho; }
bool ListaNaoOrdenada::Vazia() const { return tamanho == 0; }

Elemento* ListaNaoOrdenada::GetPrimeiro() const {
    if (Vazia()) return nullptr;
    return elementos[0];
}

Elemento* ListaNaoOrdenada::GetUltimo() const {
    if (Vazia()) return nullptr;
    return elementos[tamanho - 1];
}

void ListaNaoOrdenada::Imprimir() const {
    for (int i = 0; i < tamanho; i++){ 
        elementos[i]->ImprimirInfo();
        cout << endl;
    }
}
