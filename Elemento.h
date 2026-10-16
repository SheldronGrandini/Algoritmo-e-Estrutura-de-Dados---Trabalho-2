#pragma once //Versão moderna do ifndef, define e endif

class Elemento {
    protected:
        int id; //Atributo protegido que será a chave primária

    public:
        Elemento(int id);
        virtual ~Elemento(); //Destrutor "geral" 

        int GetId() const;
        virtual void ImprimirInfo() const = 0; //Classe abstrata com um método virtual puro
};