#pragma once
#include "ListaDuplamenteEncadeadaCircular.h"
#include "Elemento.h"

// Classe Deque (Double-Ended Queue / Fila de Dupla Ponta): permite inserir e
// remover elementos em AMBAS as extremidades.
//
// Estrutura subjacente: ListaDuplamenteEncadeadaCircular (alocação dinâmica, nó privado).
//
// Decisão de design: a lista duplamente encadeada circular é a única das três
// listas encadeadas do projeto em que TODAS as operações de extremidade
// custam O(1). Na lista simplesmente encadeada, RemoverUltimo seria O(n)
// (precisaríamos percorrer até o penúltimo nó); na duplamente encadeada linear,
// remover o último já seria O(1), mas a circular mantém a simetria e o custo
// de "voltar" ao primeiro elemento.
//
// Complexidade: Inserir/Remover/Consultar em qualquer ponta = O(1).
class Deque {
    private:
        ListaDuplamenteEncadeadaCircular lista; // Estrutura subjacente utilizada por composição

    public:
        Deque();
        virtual ~Deque();

        // Insere um elemento no início do deque (fila)
        bool InserirNoInicio(Elemento* elemento);
        // Insere um elemento no final do deque (pilha)
        bool InserirNoFinal(Elemento* elemento);

        // Remove e devolve o elemento do início do deque (nullptr se estiver vazio)
        Elemento* RemoverInicio();
        // Remove e devolve o elemento do final do deque (nullptr se estiver vazio)
        Elemento* RemoverFinal();

        // Consulta as extremidades sem remover
        Elemento* ConsultarInicio() const;
        Elemento* ConsultarFinal() const;

        bool Vazia() const;
        int GetTamanho() const;
        void Imprimir() const;
};
