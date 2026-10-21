#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

// Complexidade: O(1) - inicializa os ponteiros de início/fim e o contador.
ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada():inicio(nullptr),fim(nullptr),tamanho(0) {

}
// Complexidade: O(n) - percorre a lista liberando cada nó alocado.
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    while(inicio) {
        No* n=inicio;
        inicio=inicio->prox;
        delete n;

    }

}
// Complexidade: O(1) - aloca o nó e religa o ponteiro prox ao início anterior.
bool ListaSimplesmenteEncadeada::InserirNoInicio(Elemento* e) {
    if(!e)return false;
    No*n=new No(e);
    n->prox=inicio;
    inicio=n;
    if(!fim)fim=n;
    ++tamanho;
    return true;

}
// Complexidade: O(1) - a estrutura mantém o ponteiro "fim", dispensando percurso.
bool ListaSimplesmenteEncadeada::InserirNoFim(Elemento* e) {
    if(!e)return false;
    No*n=new No(e);
    if(fim)fim->prox=n;
    else inicio=n;
    fim=n;
    ++tamanho;
    return true;

}
// Complexidade: O(1) - desliga o nó do início e o apaga.
Elemento* ListaSimplesmenteEncadeada::RemoverPrimeiro() {
    if(!inicio)return nullptr;
    No*n=inicio;
    Elemento*e=n->dado;
    inicio=n->prox;
    if(!inicio)fim=nullptr;
    delete n;
    --tamanho;
    return e;

}
// Complexidade: O(n) - é necessário percorrer até o penúltimo nó para poder religar o ponteiro prox.
Elemento* ListaSimplesmenteEncadeada::RemoverUltimo() {
    if(!inicio)return nullptr;
    if(inicio==fim)return RemoverPrimeiro();
    No*p=inicio;
    while(p->prox!=fim)p=p->prox;
    Elemento*e=fim->dado;
    delete fim;
    fim=p;
    fim->prox=nullptr;
    --tamanho;
    return e;

}
// Complexidade: O(n) - busca linear pelo ID e religação dos ponteiros vizinhos.
bool ListaSimplesmenteEncadeada::RemoverPeloId(int id) {
    No*p=inicio,*ant=nullptr;
    while(p&&p->dado->GetId()!=id) {
        ant=p;
        p=p->prox;

    }
    if(!p)return false;
    if(ant)ant->prox=p->prox;
    else inicio=p->prox;
    if(p==fim)fim=ant;
    delete p;
    --tamanho;
    return true;

}
// Complexidade: O(n) - busca linear, percorre os nós sequencialmente.
Elemento* ListaSimplesmenteEncadeada::BuscarPeloId(int id)const {
    for(No*p=inicio;p;p=p->prox)if(p->dado->GetId()==id)return p->dado;
    return nullptr;

}
// Complexidade: O(1) - acesso direto ao ponteiro do início da lista.
Elemento* ListaSimplesmenteEncadeada::GetPrimeiro()const {
    return inicio?inicio->dado:nullptr;

}
// Complexidade: O(1) - acesso direto ao ponteiro do fim da lista.
Elemento* ListaSimplesmenteEncadeada::GetUltimo()const {
    return fim?fim->dado:nullptr;

}
// Complexidade: O(1) - comparação do contador com zero.
bool ListaSimplesmenteEncadeada::Vazia()const {
    return tamanho==0;

}
// Complexidade: O(1) - retorna o contador mantido em memória.
int ListaSimplesmenteEncadeada::GetTamanho()const {
    return tamanho;

}
// Complexidade: O(n) - percorre todos os nós chamando ImprimirInfo (o custo real inclui a saída de tela).
void ListaSimplesmenteEncadeada::Imprimir() const {
    if (!inicio) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    No* p = inicio;
    while (p != nullptr) {
        p->dado->ImprimirInfo();
        std::cout << "-----------------------" << std::endl;
        p = p->prox;
    }
}