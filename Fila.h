#pragma once
#include "ListaNaoOrdenada.h"
#include "Elemento.h"

// Classe Fila sequencial implementada via composição (FIFO: First In, First Out)
// Conforme solicitado no trabalho, esta implementação apresenta a ineficiência de Desenfileirar O(n)
// servindo de base para a justificativa e criação da FilaCircular
class Fila {
    private:
        ListaNaoOrdenada lista; // Estrutura subjacente utilizada por composição
        int capacidadeMaxima;   // Capacidade máxima estipulada para a fila

    public:
        // Construtor definindo uma capacidade limite (padrão de 100 elementos)
        Fila(int capacidadeMaxima = 100);
        virtual ~Fila();

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

// Apelido para clareza entre sequencial e encadeada
using FilaSequencial = Fila;
