#pragma once
#include "Elemento.h"
class ListaDuplamenteEncadeada {
private:
    class No {
         public: Elemento* dado;
         No* ant;
         No* prox;
         No(Elemento*e):dado(e),ant(nullptr),prox(nullptr) {

        }

    };
     No* inicio;
     No* fim;
     int tamanho;
     public: ListaDuplamenteEncadeada();
     ~ListaDuplamenteEncadeada();
     ListaDuplamenteEncadeada(const ListaDuplamenteEncadeada&)=delete;
     ListaDuplamenteEncadeada& operator=(const ListaDuplamenteEncadeada&)=delete;
     void Imprimir() const;
     bool InserirNoInicio(Elemento*);
     bool InserirNoFim(Elemento*);
     Elemento* RemoverPrimeiro();
     Elemento* RemoverUltimo();
     bool RemoverPeloId(int);
     Elemento* BuscarPeloId(int) const;
     bool Vazia() const;
     int GetTamanho() const;

};
