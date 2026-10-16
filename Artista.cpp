#include "Artista.h"
#include <iostream>
using namespace std;

//Método construtor que utiliza o método construtor de Elemento e o atributo nome próprio do Artista
Artista::Artista(int id, string nome) : Elemento(id){
    this -> nome = nome;
}

//Método destrutor vazio
Artista::~Artista(){};

//Método público para acessar o atributo nome privado
string Artista::GetNome() const{
    return nome;
}

//Método para mostrar as informações do Artista (id e nome)
void Artista::ImprimirInfo() const {
    cout << "O id do artista é " << Elemento::GetId() << endl;
    cout << "O nome do artista é " << Artista::GetNome() << endl;
}