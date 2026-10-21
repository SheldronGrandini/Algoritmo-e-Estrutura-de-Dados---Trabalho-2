#include "Elemento.h"

//Método construtor que utiliza um id como parâmetro
// Complexidade: O(1) - atribui a chave primária ao atributo protegido.
Elemento::Elemento(int id){
    this -> id = id;
}

//Método destrutor que permanece vazio
// Complexidade: O(1) - destrutor vazio; existe para permitir a destruição polimórfica.
Elemento::~Elemento(){};

//Método que retorna o id, necessário devido ao encapsulamento
// Complexidade: O(1) - retorna a chave primária.
int Elemento::GetId() const{
    return id;
}
