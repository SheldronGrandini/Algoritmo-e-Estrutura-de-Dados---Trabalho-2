#pragma once
#include "Elemento.h"

// Lista sequencial que mantem os elementos em ordem crescente de ID.
class ListaOrdenada {
private:
    Elemento** elementos;
    int tamanho;
    int capacidade;

    void AumentarCapacidade();
    int EncontrarPosicao(int id) const;

public:
    ListaOrdenada();
    ~ListaOrdenada();

    ListaOrdenada(const ListaOrdenada&) = delete;
    ListaOrdenada& operator=(const ListaOrdenada&) = delete;

    bool InserirNoInicio(Elemento* elemento);
    bool InserirNoFinal(Elemento* elemento);
    void RemoverPrimeiro();
    void RemoverUltimo();
    bool RemoverPeloId(int id);
    Elemento* BuscarPeloId(int id) const;
    bool AlterarPeloId(int id, Elemento* novoElemento);
    int GetTamanho() const;
    bool Vazia() const;
    void Imprimir() const;
};
