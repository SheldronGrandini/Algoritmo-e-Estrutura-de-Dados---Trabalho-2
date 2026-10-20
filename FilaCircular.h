#pragma once
#include "Elemento.h"

// Classe FilaCircular: Proposta de solução eficiente para a ineficiência da Fila sequencial tradicional.
// Utiliza um buffer circular com aritmética modular (índice % capacidade), garantindo que
// tanto o enfileiramento quanto o desenfileiramento sejam executados em tempo constante O(1).
class FilaCircular {
    private:
        Elemento** elementos; // Vetor dinâmico de ponteiros para Elemento
        int inicio;           // Índice da frente da fila no vetor
        int tamanho;          // Quantidade de elementos atualmente armazenados
        int capacidade;       // Capacidade máxima de armazenamento da fila circular

    public:
        // Construtor que inicializa a fila com a capacidade estipulada (padrão 10)
        FilaCircular(int capacidade = 10);
        virtual ~FilaCircular();

        // Prevenção de cópias rasas acidentais
        FilaCircular(const FilaCircular&) = delete;
        FilaCircular& operator=(const FilaCircular&) = delete;

        // Operações da fila - todas otimizadas para O(1)
        bool Enfileirar(Elemento* elemento);
        bool Desenfileirar();
        Elemento* ConsultarFrente() const;
        bool FilaVazia() const;
        bool FilaCheia() const;

        // Métodos auxiliares
        int GetTamanho() const;
        int GetCapacidade() const;
        void Imprimir() const;
};
