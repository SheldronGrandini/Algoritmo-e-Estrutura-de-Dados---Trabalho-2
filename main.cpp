#include <iostream>
using namespace std;
#include "Artista.h"
#include "Musica.h"
#include "ListaOrdenada.h"
#include "ListaNaoOrdenada.h"
#include "Fila.h"
#include "Pilha.h"
#include "FilaCircular.h"

void QuebraLinha(){
    cout << endl << "==========================================" << endl << endl;
}

//Adiciona os objetos criados a uma lista sequencial ordenada e imprime a lista resultante
void TestarListaOrdenada(Elemento* vetor[], int tamanho){
    ListaOrdenada lista; //Criando uma LISTA SEQUENCIAL ORDENADA
    
    //Percorrendo o vetor com os objetos criados e adicionando a lista
    for(int i = 0; i < tamanho; i++){
        lista.InserirNoInicio(vetor[i]);
    }

    lista.Imprimir(); //Imprime a lista
}

//Adiciona os objetos criados a uma lista sequencial não ordenada e imprime a lista resultante
void TestarListaNaoOrdenada(Elemento* vetor[], int tamanho){
    ListaNaoOrdenada lista; //Criando uma LISTA SEQUENCIAL NÃO ORDENADA

    //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL NÃO ORDENADA
    for(int i = 0; i < tamanho; i++){
        lista.InserirNoFinal(vetor[i]);
    }

    lista.Imprimir(); //Imprime a lista sequencial NÃO ordenada
}

void TestarFila(Elemento* vetor[], int tamanho) {
    Fila fila; //Cria a FILA
    
    //Adiciona os objetos no iníco
    cout << "--- Enfileirando ---" << endl;
    for(int i = 0; i < tamanho; i++){
        fila.Enfileirar(vetor[i]);
    }
    
    //Remove os objetos no início
    cout << "--- Desenfileirando (FIFO) ---" << endl << endl;
    while(!fila.FilaVazia()){ 
        Elemento* frente = fila.ConsultarFrente();
        if (frente != nullptr) {
            frente->ImprimirInfo();
            cout << "-" << endl;
        }
        fila.Desenfileirar();
    }
}

int main(){
    cout << "Arquivos compilados!" << endl; //Print para confirmar que o código foi compilado

    //Instanciando objetos de Artista e Musica. 5 objetos de cada tipo
    Artista artista1(1, "Bon Jovi");
    Musica musica1(2, "Livin' On a Prayer", "Rock", 251, &artista1);
    Artista artista2(3, "Seu Jorge");
    Musica musica2(4, "Amiga da Minha Mulher", "Pagode", 248, &artista2);
    Artista artista3(5, "Alex e Ronaldo");
    Musica musica3(6, "Sexta-feira Sua Linda", "Sertanejo", 190, &artista3);
    Artista artista4(7, "Rihanna");
    Musica musica4(8, "Umbrella", "Pop", 275, &artista4);
    Artista artista5(9, "Roupa Nova");
    Musica musica5(10, "Whisky a Go-Go", "Pop Rock", 248, &artista5);

    //Criando um vetor com os objetos criados em ordem decrescente
    Elemento* objetosCriados[] = {&musica5, &artista5, &musica4, &artista4, &musica3, &artista3, &musica2, &artista2, &musica1, &artista1};
    int qtdObjetos = sizeof(objetosCriados) / sizeof(objetosCriados[0]); //Salva a quantidade de objetos criados

    int opcao = 1;
    while (opcao != 0){
        QuebraLinha();
        cout << "Escolha o que deseja testar:" << endl;
        cout << "1 - Testar Lista Sequencial Ordenada" << endl;
        cout << "2 - Testar Lista Sequencial Nao Ordenada" << endl;
        cout << "3 - Testar Fila Sequencial" << endl;
        // Adicione as futuras estruturas aqui (Pilha, Fila, Arvore, etc.)
        cout << "0 - Sair" << endl;
        cout << "Sua opcao: ";
        cin >> opcao;

        QuebraLinha();

        switch (opcao) {
            case 1: {
                cout << "[Testando Lista Ordenada]" << endl << endl;
                TestarListaOrdenada(objetosCriados, qtdObjetos); 
                break;
            }
            case 2: {
                cout << "[Testando Lista Nao Ordenada]" << endl;
                TestarListaNaoOrdenada(objetosCriados, qtdObjetos);              
                break;
            }
            case 3: {
                cout << "[Testando Fila Sequencial]" << endl;
                TestarFila(objetosCriados, qtdObjetos);
                break;
            }
            case 4: {
                cout << "[Testando Pilha Sequencial]" << endl;
                TestarFila(objetosCriados, qtdObjetos);
                break;
            }
            case 5: {
                cout << "[Testando Fila Circular Sequencial]" << endl;
                TestarFila(objetosCriados, qtdObjetos);
                break;
            }
            case 0:
                cout << "Programa encerrado!" << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}