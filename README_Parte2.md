# Parte 2 — Listas sequenciais

Esta parte implementa as classes `ListaNaoOrdenada` e `ListaOrdenada`, usando a classe abstrata `Elemento` que ja existe no projeto. Como as listas guardam ponteiros para `Elemento`, podem receber objetos derivados, como `Artista` e `Musica`.

## Funcionamento

- O vetor de ponteiros comeca com capacidade 10 e dobra quando fica cheio.
- A lista nao ordenada mantem a ordem de insercao.
- A lista ordenada mantem os elementos em ordem crescente de ID.
- As insercoes rejeitam ponteiros nulos e IDs repetidos dentro da mesma lista.
- A busca na lista nao ordenada e linear; na lista ordenada, usa busca binaria.

## Responsabilidade pelos objetos

As listas **nao sao donas dos objetos**: guardam ponteiros emprestados e nao executam `delete` nos elementos. O codigo que cria os objetos continua responsavel por libera-los, depois que nenhuma estrutura os utilizar. Essa decisao evita que uma lista destrua um `Artista` ou uma `Musica` que tambem esteja sendo usada em outra estrutura. Nao se deve usar um ponteiro depois que o objeto apontado for destruido.

As operacoes de remocao retiram o ponteiro da lista, mas nao destroem o objeto. `AlterarPeloId` troca o ponteiro armazenado pelo novo ponteiro com o mesmo ID; ela tambem nao destroi o objeto anterior. Se uma insercao ou alteracao retornar `false`, a lista nao modifica sua estrutura.

## Complexidade de tempo

| Operacao | Lista nao ordenada | Lista ordenada |
|---|---:|---:|
| `InserirNoInicio` | O(n) | O(n) |
| `InserirNoFinal` | O(n), pois verifica IDs repetidos | O(n) |
| `RemoverPrimeiro` | O(n) | O(n) |
| `RemoverUltimo` | O(1) | O(1) |
| `RemoverPeloId` | O(n) | O(n) |
| `BuscarPeloId` | O(n) | O(log n) |
| `AlterarPeloId` | O(n) | O(log n) |
| `GetTamanho` / `Vazia` | O(1) | O(1) |
| `Imprimir` | O(n) | O(n) |

As operacoes de insercao/remocao na lista ordenada podem exigir deslocamentos; por isso, apesar da busca binaria, elas continuam O(n) no pior caso.
