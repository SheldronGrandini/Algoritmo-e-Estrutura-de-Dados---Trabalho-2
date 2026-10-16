#include "Elemento.h"

//Método construtor que utiliza um id como parâmetro
Elemento::Elemento(int id){
    this -> id = id;
};

//Método destrutor que permanece vazio
Elemento::~Elemento(){};

//Método que retorna o id, necessário devido ao encapsulamento
int Elemento::getId() const{
    return id;
};
