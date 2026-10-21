#pragma once
#include "Elemento.h"
class ArvoreBinariaBusca {
private:
    class No {
         public: Elemento* dado;
         No* esq;
         No* dir;
         explicit No(Elemento*e):dado(e),esq(nullptr),dir(nullptr) {

        }

    };
     No* raiz;
     static void Limpar(No*);
     static No* Inserir(No*, Elemento*, bool&);
     static Elemento* Buscar(No*, int);
     static No* Remover(No*, int, bool&);
     static void EmOrdem(No*);
     static void PreOrdem(No*);
     static void PosOrdem(No*);
     public: ArvoreBinariaBusca();
     ~ArvoreBinariaBusca();
     ArvoreBinariaBusca(const ArvoreBinariaBusca&)=delete;
     ArvoreBinariaBusca& operator=(const ArvoreBinariaBusca&)=delete;
     bool Inserir(Elemento*);
     Elemento* BuscarPeloId(int) const;
     bool RemoverPeloId(int);
     void emOrdem() const;
     void preOrdem() const;
     void posOrdem() const;

};
