#include "ListaDuplamenteEncadeada.h"
#include <iostream>

// Complexidade: O(1) - inicializa os ponteiros de início/fim e o contador.
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada():inicio(nullptr),fim(nullptr),tamanho(0) {

}
// Complexidade: O(n) - percorre a lista liberando cada nó alocado.
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    while(inicio) {
        No*n=inicio;
        inicio=inicio->prox;
        delete n;

    }

}
// Complexidade: O(1) - aloca o nó e religa os ponteiros ant e prox.
bool ListaDuplamenteEncadeada::InserirNoInicio(Elemento*e) {
    if(!e)return false;
    No*n=new No(e);
    n->prox=inicio;
    if(inicio)inicio->ant=n;
    else fim=n;
    inicio=n;
    ++tamanho;
    return true;

}
// Complexidade: O(1) - a estrutura mantém o ponteiro "fim", dispensando percurso.
bool ListaDuplamenteEncadeada::InserirNoFim(Elemento*e) {
    if(!e)return false;
    No*n=new No(e);
    n->ant=fim;
    if(fim)fim->prox=n;
    else inicio=n;
    fim=n;
    ++tamanho;
    return true;

}
// Complexidade: O(1) - desliga o nó do início, religa o ant do novo início e o apaga.
Elemento* ListaDuplamenteEncadeada::RemoverPrimeiro() {
    if(!inicio)return nullptr;
    No*n=inicio;
    Elemento*e=n->dado;
    inicio=n->prox;
    if(inicio)inicio->ant=nullptr;
    else fim=nullptr;
    delete n;
    --tamanho;
    return e;

}
// Complexidade: O(1) - o nó anterior é acessado direto por fim->ant, dispensando percurso.
Elemento* ListaDuplamenteEncadeada::RemoverUltimo() {
    if(!fim)return nullptr;
    No*n=fim;
    Elemento*e=n->dado;
    fim=n->ant;
    if(fim)fim->prox=nullptr;
    else inicio=nullptr;
    delete n;
    --tamanho;
    return e;

}
// Complexidade: O(n) - busca linear pelo ID e religação dos ponteiros vizinhos.
bool ListaDuplamenteEncadeada::RemoverPeloId(int id) {
    for(No*p=inicio;p;p=p->prox)if(p->dado->GetId()==id) {
        if(p->ant)p->ant->prox=p->prox;
        else inicio=p->prox;
        if(p->prox)p->prox->ant=p->ant;
        else fim=p->ant;
        delete p;
        --tamanho;
        return true;

    }
    return false;

}
// Complexidade: O(n) - busca linear, percorre os nós sequencialmente.
Elemento* ListaDuplamenteEncadeada::BuscarPeloId(int id)const {
    for(No*p=inicio;p;p=p->prox)if(p->dado->GetId()==id)return p->dado;
    return nullptr;

}
// Complexidade: O(1) - comparação do contador com zero.
bool ListaDuplamenteEncadeada::Vazia()const {
    return tamanho==0;

}
// Complexidade: O(1) - retorna o contador mantido em memória.
int ListaDuplamenteEncadeada::GetTamanho()const {
    return tamanho;

}
// Complexidade: O(n) - percorre todos os nós chamando ImprimirInfo (o custo real inclui a saída de tela).
void ListaDuplamenteEncadeada::Imprimir() const {
    if (!inicio) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    No* p = inicio;
    while (p != nullptr) {
        p->dado->ImprimirInfo();
        std::cout << "-----------------------" << std::endl;
        p = p->prox;
    }
}