#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

// Complexidade: O(1) - inicializa o ponteiro de início e o contador.
ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular():inicio(nullptr),tamanho(0) {

}
// Complexidade: O(n) - remove os nós um a um, reaproveitando a lógica de religação dos ponteiros.
ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    while(tamanho)RemoverPrimeiro();

}
// Complexidade: O(1) - aloca o nó e religa os ponteiros ant e prox no ciclo.
bool ListaDuplamenteEncadeadaCircular::InserirNoInicio(Elemento*e) {
    if(!e)return false;
    No*n=new No(e);
    if(!inicio)inicio=n;
    else {
        No*f=inicio->ant;
        n->prox=inicio;
        n->ant=f;
        f->prox=n;
        inicio->ant=n;
        inicio=n;

    }
    ++tamanho;
    return true;

}
// Complexidade: O(1) - insere antes do início e atualiza inicio->ant para o novo nó.
bool ListaDuplamenteEncadeadaCircular::InserirNoFim(Elemento*e) {
    if(!e)return false;
    if(!inicio) {
        inicio=new No(e);

    } else {
        No*n=new No(e);
        No*f=inicio->ant;
        n->prox=inicio;
        n->ant=f;
        f->prox=n;
        inicio->ant=n;

    }
    ++tamanho;
    return true;

}
// Complexidade: O(1) - desliga o nó do início do ciclo e o apaga.
Elemento* ListaDuplamenteEncadeadaCircular::RemoverPrimeiro() {
    if(!inicio)return nullptr;
    No*n=inicio;
    Elemento*e=n->dado;
    if(n->prox==n)inicio=nullptr;
    else {
        n->ant->prox=n->prox;
        n->prox->ant=n->ant;
        inicio=n->prox;

    }
    delete n;
    --tamanho;
    return e;

}
// Complexidade: O(1) - o último nó é inicio->ant, acessado diretamente.
Elemento* ListaDuplamenteEncadeadaCircular::RemoverUltimo() {
    if(!inicio)return nullptr;
    return tamanho==1?RemoverPrimeiro():([&]() {
        No*n=inicio->ant;Elemento*e=n->dado;n->ant->prox=inicio;inicio->ant=n->ant;delete n;--tamanho;return e;
    })();

}
// Complexidade: O(n) - busca linear percorrendo o ciclo até o ID (ou até voltar ao início).
bool ListaDuplamenteEncadeadaCircular::RemoverPeloId(int id) {
    if(!inicio)return false;
    No*p=inicio;
    do {
        if(p->dado->GetId()==id) {
            if(p==inicio)return RemoverPrimeiro()!=nullptr;
            if(p->prox==inicio)return RemoverUltimo()!=nullptr;
            p->ant->prox=p->prox;
            p->prox->ant=p->ant;
            delete p;
            --tamanho;
            return true;

        }
        p=p->prox;

    }
    while(p!=inicio);
    return false;

}
// Complexidade: O(n) - busca linear percorrendo o ciclo até o ID (ou até voltar ao início).
Elemento* ListaDuplamenteEncadeadaCircular::BuscarPeloId(int id)const {
    if(!inicio)return nullptr;
    No*p=inicio;
    do {
        if(p->dado->GetId()==id)return p->dado;
        p=p->prox;

    }
    while(p!=inicio);
    return nullptr;

}
// Complexidade: O(1) - o nó inicial sempre aponta direto para o primeiro elemento.
Elemento* ListaDuplamenteEncadeadaCircular::GetPrimeiro()const {
    return inicio?inicio->dado:nullptr;

}
// Complexidade: O(1) - em uma lista circular o último nó é sempre inicio->ant.
Elemento* ListaDuplamenteEncadeadaCircular::GetUltimo()const {
    return inicio?inicio->ant->dado:nullptr;

}
// Complexidade: O(1) - comparação do contador com zero.
bool ListaDuplamenteEncadeadaCircular::Vazia()const {
    return tamanho==0;

}
// Complexidade: O(1) - retorna o contador mantido em memória.
int ListaDuplamenteEncadeadaCircular::GetTamanho()const {
    return tamanho;

}
// Complexidade: O(n) - percorre o ciclo uma vez chamando ImprimirInfo (o custo real inclui a saída de tela).
void ListaDuplamenteEncadeadaCircular::Imprimir() const {
    if (!inicio) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }
    
    No* p = inicio;
    do {
        p->dado->ImprimirInfo();
        std::cout << "-----------------------" << std::endl;
        p = p->prox;
    } while (p != inicio);
}