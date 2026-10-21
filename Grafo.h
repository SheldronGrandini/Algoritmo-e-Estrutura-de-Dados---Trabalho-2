#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Grafo  {
     private: // Duas representações: matriz de adjacência e lista de adjacência.
std::vector<int> ids;
     std::unordered_map<int, int> indice;
     std::vector<std::vector<bool>> matriz;
     std::unordered_map<int, std::vector<int>> lista;
     public: bool AdicionarVertice(int id);
     bool AdicionarAresta(int idA, int idB);
     bool SaoVizinhos(int idA, int idB) const;
     int Grau(int id) const;
     std::vector<int> BuscaEmLargura(int inicio) const;
     std::vector<int> BuscaEmProfundidade(int inicio) const;
     int QuantidadeVertices() const;

};
