#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada():inicio(nullptr),fim(nullptr),tamanho(0) {

}
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    while(inicio) {
        No* n=inicio;
        inicio=inicio->prox;
        delete n;

    }

}
bool ListaSimplesmenteEncadeada::InserirNoInicio(Elemento* e) {
    if(!e)return false;
    No*n=new No(e);
    n->prox=inicio;
    inicio=n;
    if(!fim)fim=n;
    ++tamanho;
    return true;

}
bool ListaSimplesmenteEncadeada::InserirNoFim(Elemento* e) {
    if(!e)return false;
    No*n=new No(e);
    if(fim)fim->prox=n;
    else inicio=n;
    fim=n;
    ++tamanho;
    return true;

}
Elemento* ListaSimplesmenteEncadeada::RemoverPrimeiro() {
    if(!inicio)return nullptr;
    No*n=inicio;
    Elemento*e=n->dado;
    inicio=n->prox;
    if(!inicio)fim=nullptr;
    delete n;
    --tamanho;
    return e;

}
Elemento* ListaSimplesmenteEncadeada::RemoverUltimo() {
    if(!inicio)return nullptr;
    if(inicio==fim)return RemoverPrimeiro();
    No*p=inicio;
    while(p->prox!=fim)p=p->prox;
    Elemento*e=fim->dado;
    delete fim;
    fim=p;
    fim->prox=nullptr;
    --tamanho;
    return e;

}
bool ListaSimplesmenteEncadeada::RemoverPeloId(int id) {
    No*p=inicio,*ant=nullptr;
    while(p&&p->dado->GetId()!=id) {
        ant=p;
        p=p->prox;

    }
    if(!p)return false;
    if(ant)ant->prox=p->prox;
    else inicio=p->prox;
    if(p==fim)fim=ant;
    delete p;
    --tamanho;
    return true;

}
Elemento* ListaSimplesmenteEncadeada::BuscarPeloId(int id)const {
    for(No*p=inicio;p;p=p->prox)if(p->dado->GetId()==id)return p->dado;
    return nullptr;

}
bool ListaSimplesmenteEncadeada::Vazia()const {
    return tamanho==0;

}
int ListaSimplesmenteEncadeada::GetTamanho()const {
    return tamanho;

}
void ListaSimplesmenteEncadeada::Imprimir() const {
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