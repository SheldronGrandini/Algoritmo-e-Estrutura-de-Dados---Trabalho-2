#pragma once
#include "Elemento.h"
#include <string>

class Artista: public Elemento{
    private:
        std::string nome; //O nome do artista só pode ser acessado pela própria classe
    
    public:
        Artista(int id, std::string nome); //Método construtor com nome como parâmetro
        virtual ~Artista(); //Método destrutor

        std::string GetNome() const; //Método público para acessar o nome privado
        virtual void ImprimirInfo() const override; //Método abstrato de Elemento que será sobreescrito
};