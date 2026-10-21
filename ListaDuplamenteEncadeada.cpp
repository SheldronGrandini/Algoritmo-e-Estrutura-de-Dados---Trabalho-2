#include "ListaDuplamenteEncadeada.h"
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada():inicio(nullptr),fim(nullptr),tamanho(0) {

}
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    while(inicio) {
        No*n=inicio;
        inicio=inicio->prox;
        delete n;

    }

}
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
Elemento* ListaDuplamenteEncadeada::BuscarPeloId(int id)const {
    for(No*p=inicio;p;p=p->prox)if(p->dado->GetId()==id)return p->dado;
    return nullptr;

}
bool ListaDuplamenteEncadeada::Vazia()const {
    return tamanho==0;

}
int ListaDuplamenteEncadeada::GetTamanho()const {
    return tamanho;

}
