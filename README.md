# Trabalho 2 — Algoritmo e Estrutura de Dados

**Disciplina:** Algoritmo e Estrutura de Dados  
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

- **Pilha (LIFO — Last In, First Out):** o último elemento inserido é o primeiro a ser removido. As operações típicas são `Empilhar`, `Desempilhar` e `ConsultarTopo`.
- **Fila (FIFO — First In, First Out):** o primeiro elemento inserido é o primeiro a ser removido. As operações típicas são `Enfileirar`, `Desenfileirar` e `ConsultarFrente`.

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

Seguindo o enunciado, nesta parte também foram implementados **Pilha, Fila e Deque como adaptadores** que funcionam por **composição** sobre as listas encadeadas:

- **`PilhaEncadeada`** — composta sobre a `ListaSimplesmenteEncadeada`. A pilha empilha no **início** e desempilha do **início** da lista, porque em lista encadeada `InserirNoInicio` e `RemoverPrimeiro` são ambas **O(1)**. Empilhar no fim exigiria `RemoverUltimo`, que é **O(n)** na lista simplesmente encadeada.
- **`FilaEncadeada`** — composta sobre a `ListaSimplesmenteEncadeada`. Enfileira no **fim** (`InserirNoFim`, O(1)) e desenfileira do **início** (`RemoverPrimeiro`, O(1)). Diferentemente da fila sequencial, aqui nada precisa ser deslocado: apenas os ponteiros são religados, de modo que o `Desenfileirar` passa a ser **O(1) estrito**.
- **`Deque`** (fila de dupla ponta) — composta sobre a `ListaDuplamenteEncadeadaCircular`, a única das três listas encadeadas em que **todas** as operações de extremidade são O(1), inclusive a remoção do último elemento (que na circular é simplesmente `inicio->ant`).


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

## 7. Decisões de design

O trabalho foi conduzido a partir de um conjunto de decisões explícitas, todas orientadas pelo enunciado:

1. **Um único ponto de entrada abstrato (`Elemento`).** Toda estrutura é um *contêiner* de `Elemento*`. Isso permitiu listas **heterogêneas** — a mesma lista armazena `Artista` e `Musica` e chama a versão correta de `ImprimirInfo()` para cada tipo (requisito de avaliação do enunciado).
2. **Composição em vez de reimplementação.** A `Pilha` e a `Fila` sequenciais foram implementadas por **composição** sobre a `ListaNaoOrdenada`, com um atributo **privado** que é uma instância da lista. Optamos pela lista **não ordenada** porque as operações de que a pilha e a fila precisam (`InserirNoFinal`, `RemoverUltimo`, `GetPrimeiro`, `GetUltimo`, `Vazia`) são as mais baratas nessa representação, enquanto na lista ordenada a inserção exigiria deslocamento O(n) sem nenhum ganho funcional. A composição também mantém o **acoplamento fraco**: a pilha depende apenas da *interface* da lista, e não da sua implementação.
3. **Correção explícita da ineficiência da fila.** A `Fila` sequencial tem `Desenfileirar` em **O(n)** (todos os n−1 elementos são deslocados para a esquerda). A `FilaCircular` foi criada exatamente para corrigir isso: com índices `inicio`/`tamanho` e aritmética modular (`(inicio + 1) % capacidade`), o desenfileirar passa a ser **O(1) estrito**, sem realocação nem deslocamento. A distinção entre fila vazia e fila cheia é feita por um **contador explícito**, o que torna os dois estados inequívocos (a alternativa clássica seria sacrificar uma posição do vetor).
4. **Escolha da estrutura subjacente por critério de complexidade.** Cada adaptador foi colocado sobre a lista que minimiza o custo das operações que ele precisa:
   - `Pilha` → `ListaNaoOrdenada` (topo em O(1));
   - `Fila` → `ListaNaoOrdenada` (frente em O(1), com a ineficiência do fundo propositalmente mantida e documentada);
   - `FilaCircular` → vetor circular próprio (O(1) nas duas pontas);
   - `PilhaEncadeada` → `ListaSimplesmenteEncadeada`, empilhando no início (O(1) nas duas operações);
   - `FilaEncadeada` → `ListaSimplesmenteEncadeada` (O(1) nas duas pontas);
   - `Deque` → `ListaDuplamenteEncadeadaCircular` (O(1) nas duas pontas, inclusive na remoção do último).
5. **Encapsulamento do nó.** O enunciado exige que a definição dos nós seja uma **classe privada dentro da própria classe** da estrutura. Isso foi feito em todas as estruturas encadeadas e na árvore: a classe `No` é declarada na seção `private:`, de modo que o usuário final sequer consegue nomear o tipo. O `main.cpp` só interage com as estruturas pelos **métodos públicos** — qualquer tentativa de acessar membros internos resulta em erro de compilação.
6. **Uma única rotina de busca binária reutilizada.** Na `ListaOrdenada`, `EncontrarPosicao` devolve o índice de inserção (*lower bound*) e é aproveitada por `BuscarPeloId`, `InserirNoInicio`, `RemoverPeloId` e `AlterarPeloId`. Isso evita quatro implementações parecidas e centraliza a lógica de ordenação.
7. **Árvore binária de busca simples, sem balanceamento.** O enunciado pede a ABB com a propriedade fundamental baseada no `ID` do nó, e é isso que foi implementado. A complexidade O(log n) vale para árvores aproximadamente balanceadas; no pior caso (inserções em ordem já ordenada) a árvore degenera e o custo passa a ser O(n). Manter a altura controlada exigiria árvores auto-balanceadas (AVL, Red-Black), que estão fora do escopo pedido.
8. **Grafo com as duas representações simultaneamente.** Matriz de adjacência (`O(1)` para verificar vizinhos, `O(V²)` de espaço) e lista de adjacência (`O(1)` para o grau, `O(V+E)` de espaço) são mantidas em sincronia, como o enunciado determina, aproveitando o que cada uma tem de melhor.
9. **Gestão de memória em duas camadas.** As estruturas são donas do **seu armazenamento** (o vetor de ponteiros e os nós), alocado com `new`/`new[]` e liberado com `delete`/`delete[]` nos destrutores. Os objetos `Elemento` são **referências não possuídas**: quem os instanciou é quem os destrói. No `main` eles são objetos de pilha, e destruí-los dentro do contêiner causaria *double free*.
10. **Cópia explicitamente proibida.** Todas as estruturas que gerenciam memória repetem o construtor de cópia e o `operator=` com `= delete`. A cópia padrão seria rasa (os dois objetos apontariam para a mesma memória) e provocationaria *double free*. É a aplicação prática da Regra dos Três.
11. **Destrutor virtual em `Elemento`.** Garante a **destruição polimórfica**: um `delete` em um `Elemento*` que aponta para uma `Musica` executa o destrutor correto, liberando os recursos da classe derivada.
12. **Complexidade documentada no código.** Cada método de manipuração das estruturas de dados possui um comentário indicando sua complexidade de tempo computacional, conforme exigido na seção de requisitos de avaliação.

## 8. Tabela de complexidades

Complexidades em **caso médio**; quando o pior caso difere, ele é indicado. `n` = número de elementos, `V` = vértices, `E` = arestas, `h` = altura da árvore, `deg` = grau de um vértice.

### Listas sequenciais

| Operação | `ListaNaoOrdenada` | `ListaOrdenada` |
|---|---|---|
| `InserirNoInicio` | O(n) — busca de duplicidade + deslocamento | O(n) — O(log n) para achar + O(n) para deslocar |
| `InserirNoFinal` | O(1) amortizado (pior caso O(n)) | O(n) — delega para `InserirNoInicio` |
| `RemoverPrimeiro` | O(n) — desloca n−1 elementos | O(n) — desloca n−1 elementos |
| `RemoverUltimo` | **O(1)** — só decrementa o tamanho | **O(1)** — só decrementa o tamanho |
| `RemoverPeloId` | O(n) | O(n) — O(log n) + deslocamento |
| `BuscarPeloId` | O(n) — busca linear | **O(log n)** — busca binária |
| `AlterarPeloId` | O(n) | **O(log n)** — busca binária |
| `GetTamanho` / `Vazia` / `GetPrimeiro` / `GetUltimo` | O(1) | O(1) |
| `Imprimir` | O(n) | O(n) |

### Pilhas e filas (alocação sequencial)

| Operação | `Pilha` | `Fila` | `FilaCircular` |
|---|---|---|---|
| Empilhar / Enfileirar | O(1) amortizado | O(1) amortizado | **O(1)** |
| Desempilhar / Desenfileirar | **O(1)** | **O(n)** ← ineficiência corrigida | **O(1)** |
| Consultar topo / frente | O(1) | O(1) | O(1) |
| Vazia / Cheia / Tamanho | O(1) | O(1) | O(1) |
| `Imprimir` | O(n) | O(n) | O(n) |

### Listas encadeadas

| Operação | Simples | Dupla | Dupla circular |
|---|---|---|---|
| `InserirNoInicio` | O(1) | O(1) | O(1) |
| `InserirNoFim` | O(1) | O(1) | O(1) |
| `RemoverPrimeiro` | O(1) | O(1) | O(1) |
| `RemoverUltimo` | **O(n)** | **O(1)** | **O(1)** |
| `RemoverPeloId` | O(n) | O(n) | O(n) |
| `BuscarPeloId` | O(n) | O(n) | O(n) |
| `Vazia` / `GetTamanho` | O(1) | O(1) | O(1) |
| `Imprimir` / destrutor | O(n) | O(n) | O(n) |

### Adaptadores encadeados

| Operação | `PilhaEncadeada` | `FilaEncadeada` | `Deque` |
|---|---|---|---|
| Empilhar / Inserir no início | **O(1)** | — | **O(1)** |
| Inserir no final | — | **O(1)** | **O(1)** |
| Desempilhar / Remover do início | **O(1)** | **O(1)** | **O(1)** |
| Remover do final | — | — | **O(1)** |
| Consultar extremidade | O(1) | O(1) | O(1) |
| Vazia / Cheia / Tamanho | O(1) | O(1) | O(1) |
| `Imprimir` | O(n) | O(n) | O(n) |

### Árvore binária de busca

| Operação | Árvore balanceada | Pior caso (degenerada) |
|---|---|---|
| `Inserir` | O(log n) | O(n) |
| `BuscarPeloId` | O(log n) | O(n) |
| `RemoverPeloId` | O(log n) | O(n) |
| `emOrdem` / `preOrdem` / `posOrdem` | O(n) | O(n) |
| Memória auxiliar dos percursos | O(h) = O(log n) | O(h) = O(n) |

### Grafo

| Operação | Complexidade | Observação |
|---|---|---|
| `AdicionarVertice` | O(V) | redimensiona a matriz de adjacência |
| `AdicionarAresta` | O(deg) | busca linear na lista para evitar duplicidade |
| `SaoVizinhos` | **O(1)** | acesso direto à matriz |
| `Grau` | **O(1)** | tamanho da lista de vizinhos |
| `BuscaEmLargura` (BFS) | **O(V + E)** | |
| `BuscaEmProfundidade` (DFS) | **O(V + E)** | |
| `QuantidadeVertices` | O(1) | |

## 9. Organização do projeto

Os arquivos de implementação e cabeçalho (`.cpp` e `.h`) devem permanecer organizados conforme a estrutura fornecida no projeto. As partes 4 e 5 são distribuídas em arquivos ZIP separados, enquanto este README reúne a descrição geral do trabalho.

As classes e os tipos auxiliares do projeto — incluindo `Elemento`, `Artista` e `Musica`, quando presentes na versão utilizada — devem ser considerados conforme suas declarações e usos reais no código.

### Estrutura dos arquivos

| Arquivo | Conteúdo |
|---|---|
| `Elemento.h/.cpp` | Classe abstrata base, atributo `id` protegido e `ImprimirInfo()` virtual pura |
| `Artista.h/.cpp` | `Artista : public Elemento` — atributos `id` e `nome` |
| `Musica.h/.cpp` | `Musica : public Elemento` — atributos `id`, `nome`, `genero`, `duracaoSegundos` e `cantor` |
| `ListaNaoOrdenada.h/.cpp` | Lista sequencial sem ordenação (vetor de ponteiros) |
| `ListaOrdenada.h/.cpp` | Lista sequencial ordenada por ID, com busca binária |
| `Pilha.h/.cpp` | Pilha sequencial por composição sobre `ListaNaoOrdenada` |
| `Fila.h/.cpp` | Fila sequencial por composição sobre `ListaNaoOrdenada` |
| `FilaCircular.h/.cpp` | Fila circular com aritmética modular (O(1) nas duas pontas) |
| `ListaSimplesmenteEncadeada.h/.cpp` | Lista encadeada simples, com `No` privado |
| `ListaDuplamenteEncadeada.h/.cpp` | Lista encadeada dupla, com `No` privado |
| `ListaDuplamenteEncadeadaCircular.h/.cpp` | Lista encadeada dupla circular, com `No` privado |
| `PilhaEncadeada.h/.cpp` | Pilha encadeada por composição sobre `ListaSimplesmenteEncadeada` |
| `FilaEncadeada.h/.cpp` | Fila encadeada por composição sobre `ListaSimplesmenteEncadeada` |
| `Deque.h/.cpp` | Fila de dupla ponta por composição sobre `ListaDuplamenteEncadeadaCircular` |
| `ArvoreBinariaBusca.h/.cpp` | ABB com `No` privado, inserção/busca/remoção e os três percursos |
| `Grafo.h/.cpp` | Matriz de adjacência + lista de adjacência, BFS e DFS |
| `main.cpp` | Menu de demonstração com as 13 estruturas testadas |

## 10. Compilação e execução

Todos os arquivos-fonte (`.cpp`) do projeto são compilados em conjunto com um compilador compatível com C++11:

```bash
g++ -std=c++11 *.cpp -o trabalho
```

Execute o comando na pasta que contém os arquivos `.cpp` e `.h`.

O `main.cpp` abre um menu interativo com uma opção de teste para cada estrutura implementada:

```
1 - Lista Sequencial Ordenada        8 - Lista Duplamente Encadeada Circular
2 - Lista Sequencial Nao Ordenada     9 - Arvore Binaria de Busca
3 - Fila Sequencial                  10 - Grafo
4 - Pilha Sequencial                 11 - Pilha Encadeada
5 - Fila Circular Sequencial         12 - Fila Encadeada
6 - Lista Simplesmente Encadeada     13 - Deque
7 - Lista Duplamente Encadeada        0 - Sair
```

## 11. Conclusão

O trabalho reúne diferentes estruturas de dados e evidencia que cada uma possui propriedades, operações e custos próprios. A análise de complexidade ajuda a comparar as alternativas e a compreender como a organização dos dados afeta a eficiência dos algoritmos. A implementação em C++ também exige cuidado com índices, ponteiros e gerenciamento de memória.