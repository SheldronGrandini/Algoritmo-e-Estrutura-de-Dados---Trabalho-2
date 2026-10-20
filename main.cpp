#include <iostream>
using namespace std;
#include "Artista.h"
#include "Musica.h"
#include "ListaOrdenada.h"
#include "ListaNaoOrdenada.h"

int main(){
    cout << "Arquivos compilados" << endl; //Print para confirmar que o código foi compilado
    cout << "=============================" << endl; //Quebra linha

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

    //Adicionando objetos a uma LISTA SEQUENCIAL ORDENADA
    //Adicionamos no início e no fim, para mostrar que não há diferença
    ListaOrdenada listaEmOrdem;
    listaEmOrdem.InserirNoInicio(&musica5);
    listaEmOrdem.InserirNoInicio(&artista5);
    listaEmOrdem.InserirNoInicio(&musica4);
    listaEmOrdem.InserirNoFinal(&artista4);
    listaEmOrdem.InserirNoFinal(&musica3);
    listaEmOrdem.InserirNoFinal(&artista3);
    listaEmOrdem.InserirNoInicio(&musica2);
    listaEmOrdem.InserirNoFinal(&artista2);
    listaEmOrdem.InserirNoInicio(&musica1);
    listaEmOrdem.InserirNoFinal(&artista1);

    listaEmOrdem.Imprimir();

    return 0;
}