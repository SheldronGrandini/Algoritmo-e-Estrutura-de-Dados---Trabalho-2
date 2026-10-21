#pragma once
#include "ListaSimplesmenteEncadeada.h"
#include "Elemento.h"

// Classe Fila encadeada implementada via composição (FIFO: First In, First Out)
// Estrutura subjacente: ListaSimplesmenteEncadeada (alocação dinâmica, nós privados).
//
// Decisão de design: a fila enfileira no FIM da lista e desenfileira do INÍCIO.
// Em lista encadeada, "InserirNoFim" é O(1) (graças ao ponteiro "fim" que a
// estrutura mantém) e "RemoverPrimeiro" é O(1). Diferentemente da fila
// sequencial (que sofria O(n) ao remover o primeiro), aqui as duas pontas
// custam O(1) porque nada precisa ser deslocado: basta religar os ponteiros.
//
// Diferença em relação a Fila (sequencial): a lista encadeada NÃO faz
// verificação de ID duplicado, portanto Enfileirar é estritamente O(1).
class FilaEncadeada {
    private:
        ListaSimplesmenteEncadeada lista; // Estrutura subjacente utilizada por composição
        int capacidadeMaxima;             // Capacidade máxima estipulada para a fila

    public:
        // Construtor definindo uma capacidade limite (padrão de 100 elementos)
        FilaEncadeada(int capacidadeMaxima = 100);
        virtual ~FilaEncadeada();

        // Operações fundamentais da fila
        bool Enfileirar(Elemento* elemento);
        bool Desenfileirar();
        Elemento* ConsultarFrente() const;
        bool FilaVazia() const;
        bool FilaCheia() const;

        // Métodos utilitários
        int GetTamanho() const;
        void Imprimir() const;
};
