#include "ListaDuplamenteEncadeadaCircular.h"
ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular():inicio(nullptr),tamanho(0) {

}
ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    while(tamanho)RemoverPrimeiro();

}
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
Elemento* ListaDuplamenteEncadeadaCircular::RemoverUltimo() {
    if(!inicio)return nullptr;
    return tamanho==1?RemoverPrimeiro():([&]() {
        No*n=inicio->ant;Elemento*e=n->dado;n->ant->prox=inicio;inicio->ant=n->ant;delete n;--tamanho;return e;
    })();

}
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
bool ListaDuplamenteEncadeadaCircular::Vazia()const {
    return tamanho==0;

}
int ListaDuplamenteEncadeadaCircular::GetTamanho()const {
    return tamanho;

}
