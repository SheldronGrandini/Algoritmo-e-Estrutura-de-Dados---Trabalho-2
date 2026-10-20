#pragma once
#include "ListaNaoOrdenada.h"
#include "Elemento.h"

// Classe Pilha sequencial implementada via composição (LIFO: Last In, First Out)
// Conforme solicitado no PDF, reutiliza a ListaNaoOrdenada para garantir O(1) no topo
class Pilha {
    private:
        ListaNaoOrdenada lista; // Estrutura subjacente utilizada por composição
        int capacidadeMaxima;   // Capacidade máxima estipulada para a pilha

    public:
        // Construtor definindo uma capacidade limite (padrão de 100 elementos)
        Pilha(int capacidadeMaxima = 100);
        virtual ~Pilha();

        // Operações fundamentais exigidas na especificação do trabalho
        bool Empilhar(Elemento* elemento);
        bool Desempilhar();
        Elemento* ConsultarTopo() const;
        bool PilhaVazia() const;
        bool PilhaCheia() const;

        // Métodos utilitários
        int GetTamanho() const;
        void Imprimir() const;
};

// Apelido para manter consistência semântica caso prefiram PilhaSequencial
using PilhaSequencial = Pilha;
