#include "Musica.h"
#include <iostream>
using namespace std;

//Método construtor que utiliza o método construtor de Elemento e os atributos nome, genero, duracaoSegundos e cantor de Musica.
Musica::Musica(int id, string nome, string genero, int duracao, Artista* cantor) : Elemento(id){
    this -> nome = nome;
    this -> genero = genero;
    duracaoSegundos = duracao;
    this -> cantor = cantor;
}

//Método destrutor vazio
Musica::~Musica(){};

//Método público para acessar o atributo nome privado
string Musica::GetNome() const{
    return nome;
}

//Método público para acessar o atributo genero privado
string Musica::GetGenero() const{
    return genero;
}

//Método público para acessar o atributo duracaoSegundos privado
int Musica::GetDuracao() const{
    return duracaoSegundos;
}

//Método público para acessar o atributo cantor privado
Artista* Musica::GetCantor() const{
    return cantor;
}

//Método para mostrar as informações da Música (id, nome, gênero, duração, artista associado)
//Removemos o Musica::Get... para simplificar o código, uma vez que o compilador já reconhece a classe atual
void Musica::ImprimirInfo() const {
    cout << "O id da musica e " << GetId() << endl;
    cout << "O nome da musica e " << GetNome() << endl;
    cout << "O genero da musica e " << GetGenero() << endl;
    cout << "A duracao da musica em segundos e " << GetDuracao() << endl;
    cout << "O artista que canta a musica e " << GetCantor() -> GetNome() << endl; //Foi necessário utilizar GetNome(), pois o método GetCantor() retorna o "objeto inteiro".
}                                                                                  //De modo que o dado mostrado seria o enderço do objeto Artista associado.