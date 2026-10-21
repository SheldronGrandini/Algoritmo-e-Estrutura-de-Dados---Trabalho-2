#include "ArvoreBinariaBusca.h"
#include <iostream>
// Complexidade: O(1) - a árvore começa vazia, sem raiz.
ArvoreBinariaBusca::ArvoreBinariaBusca():raiz(nullptr) {

}
// Complexidade: O(n) - percorre todos os nós uma vez, em pós-ordem.
void ArvoreBinariaBusca::Limpar(No*n) {
    if(!n)return;
    Limpar(n->esq);
    Limpar(n->dir);
    delete n;

}
// Complexidade: O(n) - libera a árvore recursivamente em pós-ordem (filhos antes do pai).
ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    Limpar(raiz);

}
// Complexidade: O(h) - desce até a posição de inserção. Balanceada O(log n), pior caso O(n).
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
// Complexidade: O(h) - O(log n) em árvore balanceada, O(n) no pior caso (árvore degenerada).
bool ArvoreBinariaBusca::Inserir(Elemento*e) {
    if(!e)return false;
    bool ok=false;
    raiz=Inserir(raiz,e,ok);
    return ok;

}
// Complexidade: O(h) - O(log n) em árvore balanceada, O(n) no pior caso (árvore degenerada).
Elemento* ArvoreBinariaBusca::Buscar(No*n,int id) {
    while(n) {
        if(id==n->dado->GetId())return n->dado;
        n=id<n->dado->GetId()?n->esq:n->dir;

    }
    return nullptr;

}
// Complexidade: O(h) - O(log n) em árvore balanceada, O(n) no pior caso (árvore degenerada).
Elemento* ArvoreBinariaBusca::BuscarPeloId(int id)const {
    return Buscar(raiz,id);

}
// Complexidade: O(h) - O(log n) em árvore balanceada, O(n) no pior caso (árvore degenerada).
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
// Complexidade: O(h) - O(log n) em árvore balanceada, O(n) no pior caso (árvore degenerada).
bool ArvoreBinariaBusca::RemoverPeloId(int id) {
    bool ok=false;
    raiz=Remover(raiz,id,ok);
    return ok;

}
// Complexidade: O(n) - visita todos os nós; a pilha de chamadas ocupa O(h).
void ArvoreBinariaBusca::EmOrdem(No*n) {
    if(n) {
        EmOrdem(n->esq);
        std::cout<<n->dado->GetId()<<' ';
        EmOrdem(n->dir);

    }

}
// Complexidade: O(n) - visita todos os nós; a pilha de chamadas ocupa O(h).
void ArvoreBinariaBusca::PreOrdem(No*n) {
    if(n) {
        std::cout<<n->dado->GetId()<<' ';
        PreOrdem(n->esq);
        PreOrdem(n->dir);

    }

}
// Complexidade: O(n) - visita todos os nós; a pilha de chamadas ocupa O(h).
void ArvoreBinariaBusca::PosOrdem(No*n) {
    if(n) {
        PosOrdem(n->esq);
        PosOrdem(n->dir);
        std::cout<<n->dado->GetId()<<' ';

    }

}
// Complexidade: O(n) - delega ao percurso recursivo, que visita todos os nós.
void ArvoreBinariaBusca::emOrdem()const {
    EmOrdem(raiz);
    std::cout<<'\n';

}
// Complexidade: O(n) - delega ao percurso recursivo, que visita todos os nós.
void ArvoreBinariaBusca::preOrdem()const {
    PreOrdem(raiz);
    std::cout<<'\n';

}
// Complexidade: O(n) - delega ao percurso recursivo, que visita todos os nós.
void ArvoreBinariaBusca::posOrdem()const {
    PosOrdem(raiz);
    std::cout<<'\n';

}
