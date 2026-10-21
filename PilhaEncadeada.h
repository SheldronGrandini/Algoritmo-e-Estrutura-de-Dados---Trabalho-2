#pragma once
#include "ListaSimplesmenteEncadeada.h"
#include "Elemento.h"

// Classe Pilha encadeada implementada via composição (LIFO: Last In, First Out)
// Estrutura subjacente: ListaSimplesmenteEncadeada (alocação dinâmica, nós privados).
//
// Decisão de design: a pilha empilha no INÍCIO da lista e desempilha do INÍCIO.
// Em lista encadeada, "InserirNoInicio" e "RemoverPrimeiro" são ambas O(1).
// A alternativa (empilhar no fim / desempilhar do fim) exigiria RemoverUltimo,
// que é O(n) na lista simplesmente encadeada, pois seria preciso percorrer
// a lista até o penúltimo nó para poder religar o ponteiro "prox".
//
// Diferença em relação a Pilha (sequencial): a lista encadeada NÃO faz
// verificação de ID duplicado, portanto Empilhar é estritamente O(1).
class PilhaEncadeada {
    private:
        ListaSimplesmenteEncadeada lista; // Estrutura subjacente utilizada por composição
        int capacidadeMaxima;             // Capacidade máxima estipulada para a pilha

    public:
        // Construtor definindo uma capacidade limite (padrão de 100 elementos)
        PilhaEncadeada(int capacidadeMaxima = 100);
        virtual ~PilhaEncadeada();

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
