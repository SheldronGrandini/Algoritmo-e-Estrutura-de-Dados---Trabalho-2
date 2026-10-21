#pragma once
#include "Elemento.h"

class ListaSimplesmenteEncadeada {
private:
    class No {
         public: Elemento* dado;
         No* prox;
         No(Elemento* e):dado(e),prox(nullptr) {

        }

    };
     No* inicio;
     No* fim;
     int tamanho;
     public: ListaSimplesmenteEncadeada();
     ~ListaSimplesmenteEncadeada();
     ListaSimplesmenteEncadeada(const ListaSimplesmenteEncadeada&)=delete;
     ListaSimplesmenteEncadeada& operator=(const ListaSimplesmenteEncadeada&)=delete;
     void Imprimir() const;
     bool InserirNoInicio(Elemento*);
     bool InserirNoFim(Elemento*);
     Elemento* RemoverPrimeiro();
     Elemento* RemoverUltimo();
     bool RemoverPeloId(int);
     Elemento* BuscarPeloId(int) const;
     Elemento* GetPrimeiro() const;
     Elemento* GetUltimo() const;
     bool Vazia() const;
     int GetTamanho() const;

};
