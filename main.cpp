#include <iostream>
using namespace std;
#include "Artista.h"
#include "Musica.h"
#include "ListaOrdenada.h"
#include "ListaNaoOrdenada.h"

void QuebraLinha(){
    cout << endl << "=============================" << endl << endl;
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

int main(){
    cout << "Arquivos compilados!" << endl; //Print para confirmar que o código foi compilado
    QuebraLinha();

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

    //Criando estruturas
    ListaOrdenada listaEmOrdem; //Criando uma LISTA SEQUENCIAL ORDENADA
    ListaNaoOrdenada listaBaguncada; //Criando uma LISTA SEQUENCIAL NÃO ORDENADA
    
    PreencherListaOrdenada(listaEmOrdem, objetosCriados, qtdObjetos); //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL ORDENADA
    PreencherListaNaoOrdenada(listaBaguncada, objetosCriados, qtdObjetos); //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL NÃO ORDENADA

    listaEmOrdem.Imprimir(); //Imprime a lista sequencial ordenada
    QuebraLinha();
    listaBaguncada.Imprimir(); //Imprime a lista sequencial NÃO ordenada

    return 0;
}