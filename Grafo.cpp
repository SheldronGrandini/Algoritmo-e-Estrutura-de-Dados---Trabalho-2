#include "Grafo.h"
#include <queue>
#include <algorithm>
#include <functional>
bool Grafo::AdicionarVertice(int id) {
    if(indice.count(id))return false;
    int n=(int)ids.size();
    indice[id]=n;
    ids.push_back(id);
    for(auto&linha:matriz)linha.push_back(false);
    matriz.push_back(std::vector<bool>(n+1,false));
    lista[id]= {

    };
    return true;

}
bool Grafo::AdicionarAresta(int a,int b) {
    if(!indice.count(a)||!indice.count(b)||a==b)return false;
    int i=indice[a],j=indice[b];
    matriz[i][j]=matriz[j][i]=true;
    auto adiciona=[](std::vector<int>&v,int x) {
        if(std::find(v.begin(),v.end(),x)==v.end())v.push_back(x);

    };
    adiciona(lista[a],b);
    adiciona(lista[b],a);
    return true;

}
bool Grafo::SaoVizinhos(int a,int b)const {
    auto i=indice.find(a),j=indice.find(b);
    return i!=indice.end()&&j!=indice.end()&&matriz[i->second][j->second];

}
int Grafo::Grau(int id)const {
    auto it=lista.find(id);
    return it==lista.end()?-1:(int)it->second.size();

}
std::vector<int> Grafo::BuscaEmLargura(int inicio)const {
    std::vector<int> ordem;
    if(!indice.count(inicio))return ordem;
    std::unordered_set<int> visto;
    std::queue<int>q;
    q.push(inicio);
    visto.insert(inicio);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        ordem.push_back(u);
        auto it=lista.find(u);
        if(it!=lista.end())for(int v:it->second)if(visto.insert(v).second)q.push(v);

    }
    return ordem;

}
std::vector<int> Grafo::BuscaEmProfundidade(int inicio)const {
    std::vector<int> ordem;
    std::unordered_set<int>visto;
    std::function<void(int)>dfs=[&](int u) {
        visto.insert(u);
        ordem.push_back(u);
        for(int v:lista.at(u))if(!visto.count(v))dfs(v);

    };
    if(indice.count(inicio))dfs(inicio);
    return ordem;

}
int Grafo::QuantidadeVertices()const {
    return (int)ids.size();

}
