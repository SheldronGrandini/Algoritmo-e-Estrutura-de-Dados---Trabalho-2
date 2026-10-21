# Trabalho 2 — Algoritmos e Estruturas de Dados

**Disciplina:** Engenharia de Sistemas de Dados  
**Linguagem de programação:** C++  
**Integrantes do grupo:** Sheldron Grandini, Gabriel Woyames e Geliel Pereira

---

## 1. Introdução

Este trabalho tem como objetivo implementar e estudar diferentes estruturas de dados utilizando C++. Ao longo das cinco partes, são exploradas formas de armazenar, organizar, acessar e relacionar informações, considerando as operações disponíveis e suas complexidades computacionais.

As implementações permitem comparar as características de cada estrutura e compreender como a escolha da representação dos dados influencia o desempenho dos algoritmos. As complexidades indicadas neste documento são referências gerais; o custo exato depende dos detalhes de cada implementação.

## 2. Parte 1 — Listas sequenciais

Nesta parte, são estudadas listas sequenciais ordenadas e não ordenadas, que armazenam elementos em posições contíguas de memória, normalmente em um vetor.

As operações consideradas incluem inserção, remoção, busca e consulta de elementos. Em geral, acessar uma posição pelo índice custa **O(1)**. A busca linear custa **O(n)**; em uma lista ordenada, a busca binária pode custar **O(log n)**, desde que a implementação permita acesso eficiente por índice. Inserções e remoções podem exigir deslocar elementos e, nesse caso, custar **O(n)**.

## 3. Parte 2 — Pilhas e filas

Esta parte aborda duas estruturas lineares:

- **Pilha (LIFO — Last In, First Out):** o último elemento inserido é o primeiro a ser removido. As operações típicas são empilhar (*push*), desempilhar (*pop*) e consultar o topo.
- **Fila (FIFO — First In, First Out):** o primeiro elemento inserido é o primeiro a ser removido. As operações típicas são enfileirar, desenfileirar e consultar o início.

Quando implementadas de modo adequado, as operações principais de inserção e remoção podem ter complexidade **O(1)**. O custo efetivo depende da representação escolhida.

## 4. Parte 3 — Fila circular

A fila circular utiliza uma estrutura sequencial e índices que avançam circularmente, permitindo reutilizar posições liberadas no início do vetor. Essa organização evita deslocar todos os elementos a cada remoção.

Com controle adequado dos índices de início e fim, as operações de enfileirar e desenfileirar podem ser realizadas em **O(1)**. É necessário distinguir corretamente os estados de fila vazia e fila cheia.

## 5. Parte 4 — Listas encadeadas

Nesta parte, são abordadas três variações de listas encadeadas:

- **Lista simplesmente encadeada:** cada nó guarda um elemento e uma referência ao próximo nó.
- **Lista duplamente encadeada:** cada nó mantém referências para o nó seguinte e o anterior, permitindo percorrer a lista nos dois sentidos.
- **Lista duplamente encadeada circular:** os nós são ligados em ambos os sentidos, e o último e o primeiro nó ficam conectados, formando um ciclo.

A busca por um elemento normalmente custa **O(n)**. Inserções e remoções podem custar **O(1)** quando já se tem a referência ao nó ou à posição adequada; localizar essa posição por busca geralmente custa **O(n)**. Essas estruturas exigem atenção ao ajuste dos ponteiros e à liberação da memória alocada.

## 6. Parte 5 — Árvore binária de busca e grafos

### 6.1 Árvore binária de busca

A árvore binária de busca organiza as chaves de modo que, conforme a convenção adotada, valores menores ficam à esquerda e valores maiores ficam à direita de cada nó. Essa propriedade permite realizar busca, inserção e remoção percorrendo a árvore.

Em uma árvore aproximadamente balanceada, essas operações costumam custar **O(log n)**. No pior caso, quando a árvore fica degenerada, podem custar **O(n)**. A complexidade depende da forma da árvore e de a implementação realizar ou não balanceamento.

### 6.2 Grafos

Um grafo representa elementos como **vértices** e suas relações como **arestas**. Grafos podem modelar redes, conexões e caminhos entre objetos. A forma de representação — por exemplo, lista de adjacência ou matriz de adjacência — influencia o custo das operações.

Entre os algoritmos de percurso mais conhecidos estão:

- **Busca em largura (BFS):** visita os vértices por níveis, normalmente utilizando uma fila.
- **Busca em profundidade (DFS):** explora um caminho o máximo possível antes de retroceder, normalmente utilizando recursão ou uma pilha.

Com uma representação por lista de adjacência, BFS e DFS percorrem o grafo em **O(V + E)**, em que **V** é o número de vértices e **E** é o número de arestas.

## 7. Organização do projeto

Os arquivos de implementação e cabeçalho (`.cpp` e `.h`) devem permanecer organizados conforme a estrutura fornecida no projeto. As partes 4 e 5 são distribuídas em arquivos ZIP separados, enquanto este README reúne a descrição geral do trabalho.

As classes e os tipos auxiliares do projeto — incluindo `Elemento`, `Artista` e `Musica`, quando presentes na versão utilizada — devem ser considerados conforme suas declarações e usos reais no código.

## 8. Compilação e execução

A compilação depende da organização dos arquivos e da existência de um ponto de entrada (`main`). Se o projeto possuir vários arquivos-fonte, compile-os em conjunto e inclua os cabeçalhos necessários. Exemplo genérico com um compilador compatível com C++11:

```bash
g++ -std=c++11 *.cpp -o trabalho
```

Execute o comando na pasta correta do projeto. Caso existam vários arquivos com função `main`, ou se os arquivos dependerem de fontes do projeto-base, será necessário ajustar a lista de arquivos compilados.

## 9. Conclusão

O trabalho reúne diferentes estruturas de dados e evidencia que cada uma possui propriedades, operações e custos próprios. A análise de complexidade ajuda a comparar as alternativas e a compreender como a organização dos dados afeta a eficiência dos algoritmos. A implementação em C++ também exige cuidado com índices, ponteiros e gerenciamento de memória.