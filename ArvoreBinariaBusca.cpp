#include "ArvoreBinariaBusca.h"
#include <iostream>
ArvoreBinariaBusca::ArvoreBinariaBusca():raiz(nullptr) {

}
void ArvoreBinariaBusca::Limpar(No*n) {
    if(!n)return;
    Limpar(n->esq);
    Limpar(n->dir);
    delete n;

}
ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    Limpar(raiz);

}
ArvoreBinariaBusca::No* ArvoreBinariaBusca::Inserir(No*n,Elemento*e,bool&ok) {
    if(!n) {
        ok=true;
        return new No(e);

    }
    if(e->GetId()==n->dado->GetId())return n;
    if(e->GetId()<n->dado->GetId())n->esq=Inserir(n->esq,e,ok);
    else n->dir=Inserir(n->dir,e,ok);
    return n;

}
bool ArvoreBinariaBusca::Inserir(Elemento*e) {
    if(!e)return false;
    bool ok=false;
    raiz=Inserir(raiz,e,ok);
    return ok;

}
Elemento* ArvoreBinariaBusca::Buscar(No*n,int id) {
    while(n) {
        if(id==n->dado->GetId())return n->dado;
        n=id<n->dado->GetId()?n->esq:n->dir;

    }
    return nullptr;

}
Elemento* ArvoreBinariaBusca::BuscarPeloId(int id)const {
    return Buscar(raiz,id);

}
ArvoreBinariaBusca::No* ArvoreBinariaBusca::Remover(No*n,int id,bool&ok) {
    if(!n)return nullptr;
    if(id<n->dado->GetId())n->esq=Remover(n->esq,id,ok);
    else if(id>n->dado->GetId())n->dir=Remover(n->dir,id,ok);
    else {
        ok=true;
        if(!n->esq) {
            No*r=n->dir;
            delete n;
            return r;

        }
        if(!n->dir) {
            No*l=n->esq;
            delete n;
            return l;

        }
        No*s=n->dir;
        while(s->esq)s=s->esq;
        n->dado=s->dado;
        bool ignorado=false;
        n->dir=Remover(n->dir,s->dado->GetId(),ignorado);

    }
    return n;

}
bool ArvoreBinariaBusca::RemoverPeloId(int id) {
    bool ok=false;
    raiz=Remover(raiz,id,ok);
    return ok;

}
void ArvoreBinariaBusca::EmOrdem(No*n) {
    if(n) {
        EmOrdem(n->esq);
        std::cout<<n->dado->GetId()<<' ';
        EmOrdem(n->dir);

    }

}
void ArvoreBinariaBusca::PreOrdem(No*n) {
    if(n) {
        std::cout<<n->dado->GetId()<<' ';
        PreOrdem(n->esq);
        PreOrdem(n->dir);

    }

}
void ArvoreBinariaBusca::PosOrdem(No*n) {
    if(n) {
        PosOrdem(n->esq);
        PosOrdem(n->dir);
        std::cout<<n->dado->GetId()<<' ';

    }

}
void ArvoreBinariaBusca::emOrdem()const {
    EmOrdem(raiz);
    std::cout<<'\n';

}
void ArvoreBinariaBusca::preOrdem()const {
    PreOrdem(raiz);
    std::cout<<'\n';

}
void ArvoreBinariaBusca::posOrdem()const {
    PosOrdem(raiz);
    std::cout<<'\n';

}
