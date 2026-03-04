# Avaliação Individual  
## Análise Comparativa entre ShellSort e HeapSort

---

## Questão 1 (1,0 ponto)

**Enunciado:**  
Explique por que o HeapSort possui complexidade O(n log n) garantida em todos os casos, enquanto o ShellSort não possui complexidade previsível.

**Resposta:**  

O HeapSort apresenta complexidade O(n log n) garantida em todos os casos porque sua execução é composta por duas etapas bem definidas e independentes da ordem dos dados de entrada. Inicialmente, realiza-se a construção da estrutura de heap a partir do vetor original, operação que possui custo O(n). Em seguida, são realizadas n extrações do elemento raiz, cada uma com custo O(log n), devido à necessidade de reorganização da estrutura para manter a propriedade do heap. Dessa forma, o custo total do algoritmo é dado por O(n) + n · O(log n), resultando em O(n log n). Como essas operações não dependem da disposição inicial dos elementos, a complexidade mantém-se estável no melhor, médio e pior caso.

Em contraste, o ShellSort possui desempenho diretamente relacionado à sequência de incrementos (gaps) utilizada. Não há demonstração teórica geral que assegure complexidade O(n log n) para qualquer sequência de gaps. Dependendo da escolha desses incrementos e da distribuição dos dados de entrada, o algoritmo pode apresentar desempenho próximo de O(n) em situações favoráveis, mas pode também degradar para O(n²) ou valores próximos disso no pior caso. Assim, diferentemente do HeapSort, o ShellSort não possui previsibilidade assintótica garantida.

---

## Questão 2 (1,0 ponto)

**Enunciado:**  

Dado o vetor [30, 12, 45, 6, 18, 3],  
a) Construa o Max-Heap correspondente;  
b) Indique o vetor após a primeira extração da raiz.

**Resposta:**  

O processo de heapify reorganiza os elementos para que cada pai seja maior que seus filhos.
Árvore inicial: 
```
        30
       /  \
     12    45
    / \   /
   6  18 3
```
Após Build-Max-Heap → [45, 18, 30, 6, 12, 3]:
```
        45
       /  \
     18    30
    / \   /
   6  12 3
```
Após a primeira extração da raiz, o elemento 45 é removido e o último elemento (3) é movido para a raiz, seguido de uma operação de heapify para restaurar a propriedade do Max-Heap. O vetor resultante após a extração da raiz é [30, 18, 3, 6, 12]:
```
        30
       /  \
     18    3
    / \   
   6  12 
```
---

## Questão 3 (1,0 ponto)

**Enunciado:**  

Analise as afirmativas:

I – ShellSort é estável.
II – HeapSort utiliza estrutura baseada em árvore binária completa.
III – HeapSort depende da sequência de gaps.
IV – ShellSort é uma melhoria do Insertion Sort.

Assinale a alternativa correta:

A) Apenas II e IV
B) Apenas I e III
C) Apenas II, III e IV
D) Apenas II e III
E) Todas estão corretas

**Resposta:**  

A) Apenas II e IV

---

## Questão 4 (1,0 ponto)

**Enunciado:**  

Em um sistema que processa milhões de registros diariamente, qual algoritmo seria mais indicado? Justifique considerando complexidade e previsibilidade.

**Resposta:**  

Em um sistema que processa milhões de registros diariamente, o HeapSort mostra-se mais indicado entre os algoritmos analisados. Sua principal vantagem reside na garantia de complexidade O(n log n) no pior caso, independentemente da ordem ou da distribuição dos dados de entrada. Essa previsibilidade é fundamental em ambientes de produção que lidam com grandes volumes de informação, pois permite estimativas mais precisas de tempo de execução e melhor planejamento de recursos computacionais.

O ShellSort, embora possa apresentar bom desempenho médio quando utilizada uma sequência de gaps eficiente, não oferece garantia teórica de desempenho O(n log n) em todos os casos. Em situações desfavoráveis, sua complexidade pode aproximar-se de O(n²), o que representa risco significativo em aplicações de larga escala. Dessa forma, considerando critérios de escalabilidade, estabilidade de desempenho e confiabilidade, o HeapSort constitui alternativa mais adequada para sistemas com processamento intensivo de dados.

---

## Questão 5 (1,0 ponto)

**Enunciado:**  

Explique como a estrutura Heap pode ser utilizada em algoritmos de grafos e cite um exemplo.

**Resposta:**  

A estrutura Heap, normalmente implementada como um min-heap baseado em árvore binária completa, é amplamente empregada na implementação de filas de prioridade. Essa estrutura permite a realização eficiente de operações como inserção, extração do menor elemento e atualização de prioridade, todas com custo O(log n). Tais operações são essenciais em diversos algoritmos de grafos que necessitam selecionar repetidamente o elemento de menor custo ou menor distância estimada.

Um exemplo clássico é o algoritmo de Dijkstra para cálculo de caminhos mínimos em grafos com pesos não negativos. Nesse algoritmo, a heap é utilizada como fila de prioridade para armazenar pares compostos pela distância estimada e pelo vértice correspondente. A cada iteração, extrai-se o vértice com menor distância estimada e atualizam-se as distâncias de seus vizinhos, reinserindo-os ou ajustando suas prioridades na estrutura. Com o uso de binary heap, a complexidade do algoritmo torna-se O((V + E) log V), representando melhoria significativa em relação à implementação sem fila de prioridade, que poderia alcançar O(V²). 

Outro exemplo relevante é o algoritmo de Prim para obtenção de árvore geradora mínima, no qual a heap é utilizada para selecionar, a cada etapa, a aresta de menor peso que conecta a árvore parcial a um novo vértice. Em ambos os casos, a utilização da heap contribui decisivamente para a eficiência assintótica do algoritmo, justificando sua ampla adoção em aplicações práticas.