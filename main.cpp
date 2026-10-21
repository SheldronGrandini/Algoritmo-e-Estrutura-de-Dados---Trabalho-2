#include <iostream>
using namespace std;
#include "Artista.h"
#include "Musica.h"
#include "ListaOrdenada.h"
#include "ListaNaoOrdenada.h"
#include "Fila.h"
#include "Pilha.h"
#include "FilaCircular.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"
#include "ListaSimplesmenteEncadeada.h"
#include "ArvoreBinariaBusca.h"
#include "Grafo.h"
#include "PilhaEncadeada.h"
#include "FilaEncadeada.h"
#include "Deque.h"
#include <vector> // Necessário para receber o retorno das buscas do Grafo

void QuebraLinha(){
    cout << endl << "==========================================" << endl << endl;
}

//Adiciona os objetos criados a uma lista sequencial ordenada e imprime a lista resultante
void TestarListaOrdenada(Elemento* vetor[], int tamanho){
    ListaOrdenada lista; //Criando uma LISTA SEQUENCIAL ORDENADA
    
    //Percorrendo o vetor com os objetos criados e adicionando a lista
    for(int i = 0; i < tamanho; i++){
        lista.InserirNoInicio(vetor[i]);
    }

    lista.Imprimir(); //Imprime a lista
}

//Adiciona os objetos criados a uma lista sequencial não ordenada e imprime a lista resultante
void TestarListaNaoOrdenada(Elemento* vetor[], int tamanho){
    ListaNaoOrdenada lista; //Criando uma LISTA SEQUENCIAL NÃO ORDENADA

    //Percorrendo o vetor com os objetos criados e adicionando a uma LISTA SEQUENCIAL NÃO ORDENADA
    for(int i = 0; i < tamanho; i++){
        lista.InserirNoFinal(vetor[i]);
    }

    lista.Imprimir(); //Imprime a lista sequencial NÃO ordenada
}

//Adiciona os objetos criados a uma fila e imprime ao desenfileirar
void TestarFila(Elemento* vetor[], int tamanho) {
    Fila fila; //Cria a FILA
    
    //Adiciona os objetos no iníco
    cout << "--- Enfileirando ---" << endl;
    for(int i = 0; i < tamanho; i++){
        fila.Enfileirar(vetor[i]);
    }
    
    //Remove os objetos no início
    cout << "--- Desenfileirando (FIFO) ---" << endl << endl;
    while(!fila.FilaVazia()){ 
        Elemento* frente = fila.ConsultarFrente();
        if (frente != nullptr) {
            frente->ImprimirInfo(); //Imprime o elemento que está na frente
            cout << "-" << endl;
        }
        fila.Desenfileirar(); //Remove o primeiro elemento
    }
}

//Adiciona os objetos criados a uma pilha e imprime ao desempilhar
void TestarPilha(Elemento* vetor[], int tamanho) {
    Pilha pilha; //Cria a Pilha
    
    cout << "--- Empilhando ---" << endl;
    for(int i = 0; i < tamanho; i++){
        pilha.Empilhar(vetor[i]);
    }
    
    cout << "--- Desempilhando (LIFO) ---" << endl << endl;
    while(!pilha.PilhaVazia()) { 
        Elemento* topo = pilha.ConsultarTopo();
        if (topo != nullptr) {
            topo->ImprimirInfo(); //Imprime o elemento que está no topo
            cout << "-" << endl;
        }
        pilha.Desempilhar(); //Remove de fato o elemento
    }
}

//Adiciona os objetos criados a uma fila circular e imprime
void TestarFilaCircular(Elemento* vetor[], int tamanho) {
    FilaCircular fila; //Cria a fila
    
    cout << "--- Enfileirando Circular ---" << endl;
    for(int i = 0; i < tamanho; i++){
        fila.Enfileirar(vetor[i]);
    }
    
    cout << "--- Desenfileirando Circular (FIFO O(1)) ---" << endl << endl;
    while(!fila.FilaVazia()) { 
        Elemento* frente = fila.ConsultarFrente();
        if (frente != nullptr) {
            frente->ImprimirInfo(); //Imprime ao desenfileirar
            cout << "-" << endl;
        }
        fila.Desenfileirar(); //Remove o elemento
    }
}

//Adiciona os objetos criados a uma lista simplesmente encadeada e imprime ao remover
void TestarListaSimplesmenteEncadeada(Elemento* vetor[], int tamanho) {
    ListaSimplesmenteEncadeada lista; //Cria lista simplesmente encadeada
    
    cout << "--- Inserindo Metade no Inicio e Metade no Fim ---" << endl;
    for(int i = 0; i < tamanho; i++){
        if (i < tamanho / 2) {
            lista.InserirNoInicio(vetor[i]);
        } else {
            lista.InserirNoFim(vetor[i]);
        }
    }
    
    //Faz uma remoção para testar os ponteiros
    cout << "--- Removendo o Primeiro Elemento ---" << endl << endl;
    Elemento* removido = lista.RemoverPrimeiro();
    if(removido != nullptr) {
        cout << "Removido: ";
        removido->ImprimirInfo();
    }
    
    cout << endl << "--- Estado Final da Lista ---" << endl << endl;
    lista.Imprimir();
}

//Adiciona os objetos criados a uma lista duplamente encadeada e imprime ao remover
void TestarListaDuplamenteEncadeada(Elemento* vetor[], int tamanho) {
    ListaDuplamenteEncadeada lista; //Cria a lista duplamente encadeada
    
    cout << "--- Inserindo Metade no Inicio e Metade no Fim ---" << endl;
    for(int i = 0; i < tamanho; i++){
        if (i < tamanho / 2) {
            lista.InserirNoInicio(vetor[i]);
        } else {
            lista.InserirNoFim(vetor[i]);
        }
    }
    
    //Faz uma remoção para testar os ponteiros
    cout << "--- Removendo o Primeiro Elemento ---" << endl << endl;
    Elemento* removido = lista.RemoverPrimeiro();
    if(removido != nullptr) {
        cout << "Removido: ";
        removido->ImprimirInfo();
    }
    
    cout << endl << "--- Estado Final da Lista ---" << endl << endl;
    lista.Imprimir();
}

//Adiciona os objetos criados a uma lista duplamente encadeada circular e imprime ao remover
void TestarListaDuplamenteEncadeadaCircular(Elemento* vetor[], int tamanho) {
    ListaDuplamenteEncadeadaCircular lista; //Cria a lista duplamente encadeada circular
    
    cout << "--- Inserindo Metade no Inicio e Metade no Fim ---" << endl;
    for(int i = 0; i < tamanho; i++){
        if (i < tamanho / 2) {
            lista.InserirNoInicio(vetor[i]);
        } else {
            lista.InserirNoFim(vetor[i]);
        }
    }
    
    //Faz uma remoção para testar os ponteiros
    cout << "--- Removendo o Primeiro Elemento ---" << endl << endl;
    Elemento* removido = lista.RemoverPrimeiro();
    if(removido != nullptr) {
        cout << "Removido: ";
        removido->ImprimirInfo();
    }
    
    cout << endl << "--- Estado Final da Lista ---" << endl << endl;
    lista.Imprimir();
}

//Adiciona os objetos criados a uma árvore binária de busca e testa seus percursos e metodos
void TestarArvoreBinariaBusca(Elemento* vetor[], int tamanho) {
    ArvoreBinariaBusca arvore; //Cria a arvore binaria de busca
    
    cout << "--- Inserindo na Arvore Binaria de Busca ---" << endl;
    for(int i = 0; i < tamanho; i++){
        arvore.Inserir(vetor[i]);
    }
    
    //O percurso em ordem deve imprimir os IDs em ordem crescente
    cout << endl << "--- Percurso Em Ordem (IDs Crescentes) ---" << endl;
    arvore.emOrdem();
    
    cout << endl << "--- Percurso Pre-Ordem ---" << endl;
    arvore.preOrdem();
    
    cout << endl << "--- Percurso Pos-Ordem ---" << endl;
    arvore.posOrdem();
    
    cout << endl << "--- Testando Busca ---" << endl;

    //Pega o ID do primeiro elemento do vetor como cobaia
    int idTeste = vetor[0]->GetId(); 
    Elemento* buscado = arvore.BuscarPeloId(idTeste); 
    if (buscado != nullptr) {
        cout << "Elemento encontrado no ID " << idTeste << ":" << endl;
        buscado->ImprimirInfo();
    }
    
    cout << endl << "--- Testando Remocao ---" << endl;
    if (arvore.RemoverPeloId(idTeste)) {
        cout << "Elemento ID " << idTeste << " removido com sucesso da arvore." << endl;
    }
}

//Adiciona os IDs a um grafo, cria conexoes e realiza buscas em largura e profundidade
void TestarGrafo(Elemento* vetor[], int tamanho) {
    Grafo grafo; //Cria o grafo
    
    cout << "--- Adicionando Vertices no Grafo ---" << endl;
    for(int i = 0; i < tamanho; i++){
        grafo.AdicionarVertice(vetor[i]->GetId()); //O Grafo recebe o ID (int) e nao o objeto Elemento
    }
    
    cout << "--- Criando Arestas (Conexoes Ficticias) ---" << endl;
    if(tamanho >= 4) {

        //Ligando o primeiro elemento ao segundo e terceiro, e o segundo ao quarto
        grafo.AdicionarAresta(vetor[0]->GetId(), vetor[1]->GetId());
        grafo.AdicionarAresta(vetor[0]->GetId(), vetor[2]->GetId());
        grafo.AdicionarAresta(vetor[1]->GetId(), vetor[3]->GetId());
        cout << "Arestas criadas com sucesso." << endl;
    }
    
    cout << endl << "--- Testando Informacoes do Grafo ---" << endl;
    if(tamanho >= 2) {
        cout << "Grau do vertice ID " << vetor[0]->GetId() << ": " << grafo.Grau(vetor[0]->GetId()) << endl;
        cout << "ID " << vetor[0]->GetId() << " e ID " << vetor[1]->GetId() << " sao vizinhos? "
             << (grafo.SaoVizinhos(vetor[0]->GetId(), vetor[1]->GetId()) ? "Sim" : "Nao") << endl;
    }
    
    cout << endl << "--- Busca em Largura (BFS) a partir do ID " << vetor[0]->GetId() << " ---" << endl;
    vector<int> bfs = grafo.BuscaEmLargura(vetor[0]->GetId());
    cout << "Caminho BFS: ";
    for(int id : bfs) {
        cout << id << " ";
    }
    cout << endl;
    
    cout << endl << "--- Busca em Profundidade (DFS) a partir do ID " << vetor[0]->GetId() << " ---" << endl;
    vector<int> dfs = grafo.BuscaEmProfundidade(vetor[0]->GetId());
    cout << "Caminho DFS: ";
    for(int id : dfs) {
        cout << id << " ";
    }
    cout << endl;
}

//Adiciona os objetos criados a uma pilha encadeada e imprime ao desempilhar
void TestarPilhaEncadeada(Elemento* vetor[], int tamanho) {
    PilhaEncadeada pilha; //Cria a Pilha Encadeada

    cout << "--- Empilhando (Encadeada) ---" << endl;
    for(int i = 0; i < tamanho; i++){
        pilha.Empilhar(vetor[i]);
    }

    cout << "--- Desempilhando (LIFO) ---" << endl << endl;
    while(!pilha.PilhaVazia()) {
        Elemento* topo = pilha.ConsultarTopo();
        if (topo != nullptr) {
            topo->ImprimirInfo();
            cout << "-" << endl;
        }
        pilha.Desempilhar();
    }
}

//Adiciona os objetos criados a uma fila encadeada e imprime ao desenfileirar
void TestarFilaEncadeada(Elemento* vetor[], int tamanho) {
    FilaEncadeada fila; //Cria a Fila Encadeada

    cout << "--- Enfileirando (Encadeada) ---" << endl;
    for(int i = 0; i < tamanho; i++){
        fila.Enfileirar(vetor[i]);
    }

    cout << "--- Desenfileirando (FIFO O(1)) ---" << endl << endl;
    while(!fila.FilaVazia()) {
        Elemento* frente = fila.ConsultarFrente();
        if (frente != nullptr) {
            frente->ImprimirInfo();
            cout << "-" << endl;
        }
        fila.Desenfileirar();
    }
}

//Demonstra o Deque: insere alternadamente nas duas pontas e remove das duas pontas
void TestarDeque(Elemento* vetor[], int tamanho) {
    Deque deque; //Cria o Deque

    cout << "--- Inserindo metade no Início e metade no Final ---" << endl;
    for(int i = 0; i < tamanho; i++){
        if (i % 2 == 0) {
            deque.InserirNoInicio(vetor[i]);
        } else {
            deque.InserirNoFinal(vetor[i]);
        }
    }

    cout << endl << "--- Estado Inicial do Deque ---" << endl << endl;
    deque.Imprimir();

    cout << endl << "--- Removendo do Início e do Final alternadamente ---" << endl << endl;
    while(!deque.Vazia()){
        Elemento* removidoInicio = deque.RemoverInicio();
        if (removidoInicio != nullptr) {
            cout << "Removido do inicio: ";
            removidoInicio->ImprimirInfo();
        }
        Elemento* removidoFinal = deque.RemoverFinal();
        if (removidoFinal != nullptr) {
            cout << "Removido do final: ";
            removidoFinal->ImprimirInfo();
        }
        cout << "-" << endl;
    }

    cout << endl << "--- Estado Final do Deque ---" << endl << endl;
    deque.Imprimir();
}

int main(){
    cout << "Arquivos compilados!" << endl; //Print para confirmar que o código foi compilado

    //Instanciando objetos de Artista e Musica. 5 objetos de cada tipo
    Artista artista1(1, "Bon Jovi");
    Musica musica1(2, "Livin' On a Prayer", "Rock", 251, &artista1);
    Artista artista2(3, "Seu Jorge");
    Musica musica2(4, "Amiga da Minha Mulher", "Pagode", 248, &artista2);
    Artista artista3(5, "Alex e Ronaldo");
    Musica musica3(6, "Sexta-feira Sua Linda", "Sertanejo", 190, &artista3);
    Artista artista4(7, "Rihanna");
    Musica musica4(8, "Umbrella", "Pop", 275, &artista4);
    Artista artista5(9, "Roupa Nova");
    Musica musica5(10, "Whisky a Go-Go", "Pop Rock", 248, &artista5);

    //Criando um vetor com os objetos criados em ordem decrescente
    Elemento* objetosCriados[] = {&musica5, &artista5, &musica4, &artista4, &musica3, &artista3, &musica2, &artista2, &musica1, &artista1};
    int qtdObjetos = sizeof(objetosCriados) / sizeof(objetosCriados[0]); //Salva a quantidade de objetos criados

    int opcao = 1;
    while (opcao != 0){
        QuebraLinha();
        cout << "Escolha o que deseja testar:" << endl;

        cout << "1 - Testar Lista Sequencial Ordenada" << endl;
        cout << "2 - Testar Lista Sequencial Nao Ordenada" << endl;
        cout << "3 - Testar Fila Sequencial" << endl;
        cout << "4 - Testar Pilha Sequencial" << endl;
        cout << "5 - Testar Fila Circular Sequencial" << endl;
        cout << "6 - Testar Lista Simplesmente Encadeada" << endl;
        cout << "7 - Testar Lista Duplamente Encadeada" << endl;
        cout << "8 - Testar Lista Duplamente Encadeada Circular" << endl;
        cout << "9 - Testar Arvore Binaria de Busca" << endl;
        cout << "10 - Testar Grafo" << endl;
        cout << "11 - Testar Pilha Encadeada" << endl;
        cout << "12 - Testar Fila Encadeada" << endl;
        cout << "13 - Testar Deque" << endl;

        cout << "0 - Sair" << endl;
        cout << "Sua opcao: ";
        cin >> opcao;

        QuebraLinha();

        switch (opcao) {
            case 1: {
                cout << "[Testando Lista Ordenada]" << endl << endl;
                TestarListaOrdenada(objetosCriados, qtdObjetos); 
                break;
            }
            case 2: {
                cout << "[Testando Lista Nao Ordenada]" << endl;
                TestarListaNaoOrdenada(objetosCriados, qtdObjetos);              
                break;
            }
            case 3: {
                cout << "[Testando Fila Sequencial]" << endl;
                TestarFila(objetosCriados, qtdObjetos);
                break;
            }
            case 4: {
                cout << "[Testando Pilha Sequencial]" << endl;
                TestarPilha(objetosCriados, qtdObjetos);
                break;
            }
            case 5: {
                cout << "[Testando Fila Circular Sequencial]" << endl;
                TestarFilaCircular(objetosCriados, qtdObjetos);
                break;
            }
            case 6: {
                cout << "[Testando Lista Simplesmente Encadeada]" << endl;
                TestarListaSimplesmenteEncadeada(objetosCriados, qtdObjetos);
                break;
            }
            case 7: {
                cout << "[Testando Lista Duplamente Encadeada]" << endl;
                TestarListaDuplamenteEncadeada(objetosCriados, qtdObjetos);
                break;
            }
            case 8: {
                cout << "[Testando Lista Duplamente Enc. Circular]" << endl;
                TestarListaDuplamenteEncadeadaCircular(objetosCriados, qtdObjetos);
                break;
            }
            case 9: {
                cout << "[Testando Arvore Binaria de Busca]" << endl;
                TestarArvoreBinariaBusca(objetosCriados, qtdObjetos);
                break;
            }
            case 10: {
                cout << "[Testando Grafo]" << endl;
                TestarGrafo(objetosCriados, qtdObjetos);
                break;
            }
            case 11: {
                cout << "[Testando Pilha Encadeada]" << endl;
                TestarPilhaEncadeada(objetosCriados, qtdObjetos);
                break;
            }
            case 12: {
                cout << "[Testando Fila Encadeada]" << endl;
                TestarFilaEncadeada(objetosCriados, qtdObjetos);
                break;
            }
            case 13: {
                cout << "[Testando Deque]" << endl;
                TestarDeque(objetosCriados, qtdObjetos);
                break;
            }
            case 0:
                cout << "Programa encerrado!" << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}