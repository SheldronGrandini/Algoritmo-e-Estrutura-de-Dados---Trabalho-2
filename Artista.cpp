#include "Artista.h"
#include <iostream>
using namespace std;

//Método construtor que utiliza o método construtor de Elemento e o atributo nome próprio do Artista
// Complexidade: O(1) - inicializa a base e o nome (a cópia do string é O(len)).
Artista::Artista(int id, string nome) : Elemento(id){
    this -> nome = nome;
}

//Método destrutor vazio
// Complexidade: O(1) - destrutor vazio; o destrutor da base Elemento é chamado automaticamente.
Artista::~Artista(){};

//Método público para acessar o atributo nome privado
// Complexidade: O(1) - retorna o nome do artista.
string Artista::GetNome() const{
    return nome;
}

//Método para mostrar as informações do Artista (id e nome)
//Mantivemos o Elemento::GetId e Artista::GetNome para visualizar exatamente de qual classe os métodos rodam
// Complexidade: O(1) em operações; o custo real é o da saída de tela.
void Artista::ImprimirInfo() const {
    cout << "O id do artista e " << Elemento::GetId() << endl;
    cout << "O nome do artista e " << Artista::GetNome() << endl;
}