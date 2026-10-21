#include <iostream>
using namespace std;
#include "Artista.h"
#include "Musica.h"
#include "ListaOrdenada.h"
#include "ListaNaoOrdenada.h"

void QuebraLinha(){
    cout << endl << "==========================================" << endl << endl;
}

//Adiciona os objetos criados a uma lista sequencial ordenada
void PreencherListaOrdenada(ListaOrdenada& lista, Elemento* vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        lista.InserirNoInicio(vetor[i]);
    }
}

//Adiciona os objetos criados a uma lista sequencial não ordenada
void PreencherListaNaoOrdenada(ListaNaoOrdenada& lista, Elemento* vetor[], int tamanho){
        for(int i = 0; i < tamanho; i++){
        lista.InserirNoFinal(vetor[i]);
    }
}

// FALAR DE REFERENCIAS NO README (USADAS NAS FUNÇÕES ACIMA "ListaOrdenada&")
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
        // Adicione as futuras estruturas aqui (Pilha, Fila, Arvore, etc.)
        cout << "0 - Sair" << endl;
        cout << "Sua opcao: ";
        cin >> opcao;

        QuebraLinha();

        switch (opcao) {
            case 1: {
                cout << "[Testando Lista Ordenada]" << endl << endl;
                
                ListaOrdenada listaEmOrdem; //Criando uma LISTA SEQUENCIAL ORDENADA
                PreencherListaOrdenada(listaEmOrdem, objetosCriados, qtdObjetos); //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL ORDENADA
                listaEmOrdem.Imprimir(); //Imprime a lista sequencial ordenada
                
                break;
            }
            case 2: {
                cout << "[Testando Lista Nao Ordenada]" << endl;

                ListaNaoOrdenada listaBaguncada; //Criando uma LISTA SEQUENCIAL NÃO ORDENADA
                PreencherListaNaoOrdenada(listaBaguncada, objetosCriados, qtdObjetos); //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL NÃO ORDENADA
                listaBaguncada.Imprimir(); //Imprime a lista sequencial NÃO ordenada
                
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