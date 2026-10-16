#pragma once
#include "Elemento.h"
#include "Artista.h"
#include <string>

class Musica: public Elemento{
    private: //Atributos privados
        std::string nome; //O nome da música
        std::string genero; //O gênero da música 
        int duracaoSegundos; //A duração em segundos da música
        Artista* cantor; //Ponteiro apontando para um objeto da classe Artista associado a música
    
    public:
        Musica(int id, string nome, string genero, int duracao, Artista* cantor); //Método construtor com nome, gênero, duração e artista associado a música
        virtual ~Musica(); //Método destrutor

        std::string GetNome() const; //Método público para acessar o nome privado
        std::string GetGenero() const; //Método público para acessar o gênero privado
        int GetDuracao() const; //Método público para acessar a duração da música em segundos
        Artista* GetCantor() const; //Método público para acessar o Artista associado a música

        virtual void ImprimirInfo() const override; //Método abstrato de Elemento que será sobreescrito
};