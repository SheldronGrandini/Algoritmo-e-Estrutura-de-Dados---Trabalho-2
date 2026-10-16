#pragma once
#include "Elemento.h"
#include <string>
using namespace std;

class Artista: public Elemento{
    private:
        string nome; //O nome do artista só pode ser acessado pela própria classe
    
    public:
        Artista(int id, string nome); //Método construtor com nome como parâmetro
        virtual ~Artista(); //Método destrutor

        string GetNome() const; //Método público para acessar o nome privado
        virtual void ImprimirInfo() const override; //Método abstrato de Elemento que será sobreescrito
};