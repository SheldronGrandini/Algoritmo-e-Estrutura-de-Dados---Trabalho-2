#include "Artista.h"
#include <iostream>
using namespace std;

//Método construtor que utiliza o método construtor de Elemento e o atributo nome próprio do Artista
Artista::Artista(int id, string nome) : Elemento(id){
    this -> nome = nome;
}

Artista::~Artista(){};

string Artista::GetNome() const{
    return nome;
}

void Artista::ImprimirInfo() const {
    cout << "O id do artista é " << Elemento::GetId() << endl;
    cout << "O nome do artista é " << Artista::GetNome() << endl;
}

