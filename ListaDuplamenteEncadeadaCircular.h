#pragma once
#include "Elemento.h"
class ListaDuplamenteEncadeadaCircular {
private:
    class No {
         public: Elemento* dado;
         No* ant;
         No* prox;
         No(Elemento*e):dado(e),ant(this),prox(this) {

        }

    };
     No* inicio;
     int tamanho;
     public: ListaDuplamenteEncadeadaCircular();
     ~ListaDuplamenteEncadeadaCircular();
     ListaDuplamenteEncadeadaCircular(const ListaDuplamenteEncadeadaCircular&)=delete;
     ListaDuplamenteEncadeadaCircular& operator=(const ListaDuplamenteEncadeadaCircular&)=delete;
     bool InserirNoInicio(Elemento*);
     bool InserirNoFim(Elemento*);
     Elemento* RemoverPrimeiro();
     Elemento* RemoverUltimo();
     bool RemoverPeloId(int);
     Elemento* BuscarPeloId(int) const;
     bool Vazia() const;
     int GetTamanho() const;

};
