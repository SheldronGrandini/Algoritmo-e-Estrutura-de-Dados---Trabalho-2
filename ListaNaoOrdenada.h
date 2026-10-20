#pragma once
#include "Elemento.h"

// Lista sequencial sem ordenacao dos elementos.
class ListaNaoOrdenada {
private:
    Elemento** elementos;
    int tamanho;
    int capacidade;

    void AumentarCapacidade();

public:
    ListaNaoOrdenada();
    ~ListaNaoOrdenada();

    ListaNaoOrdenada(const ListaNaoOrdenada&) = delete;
    ListaNaoOrdenada& operator=(const ListaNaoOrdenada&) = delete;

    bool InserirNoInicio(Elemento* elemento);
    bool InserirNoFinal(Elemento* elemento);
    void RemoverPrimeiro();
    void RemoverUltimo();
    bool RemoverPeloId(int id);
    Elemento* BuscarPeloId(int id) const;
    bool AlterarPeloId(int id, Elemento* novoElemento);
    int GetTamanho() const;
    bool Vazia() const;
    Elemento* GetPrimeiro() const;
    Elemento* GetUltimo() const;
    void Imprimir() const;
};
