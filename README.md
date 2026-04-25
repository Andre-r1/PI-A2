## Integrantes

- Nome:Marcos Vinícius de Almeida Mendes -- 2412130059
- Nome:André Souza Mattos --------------------2422130024 
- Nome:Luiz Felipe Borges Pinho --------------- 2412130056

## Resultados

| Tipo de Busca | Tempo Médio (s) |
| ------------- | --------------- |
| Início        | 0.000098081     |
| Meio          | 0.000302570     |
| Final         | 0.000852383     |
| Inexistente   | 0.000873186     |

### Tempo Total das Execuções

1.038589300 s

### Tempo Médio Geral

0.259647325 s

## Análise

Os resultados obtidos confirmam o comportamento linear da busca sequencial, cuja complexidade é O(n).

Observa-se um crescimento progressivo no tempo médio de busca conforme a posição do elemento no vetor:

* O tempo de execução da primeira parte: menor tempo (0.024520200s)
* O tempo de execução da segunda parte (0.151284900s)
* O tempo de execução da parte final (0.426191400s)
* Inexistente: pior caso (0.436592800s)

Isso ocorre porque o algoritmo percorre o vetor elemento por elemento até encontrar o valor ou chegar ao final.

Conclui-se que a busca sequencial é pouco eficiente para grandes volumes de dados.


### Compilar o código

Abra o terminal na pasta do projeto e execute:

```
gcc main.c src/*.c -lm -o a.out
```

---


Abra esse arquivo para visualizar os tempos de execução e dados coletados.

## Estrutura do Projeto

O projeto está organizado em diretórios para facilitar a manutenção e compreensão do código:

###  `src/`

Contém os arquivos fonte (.c) do projeto, onde estão implementadas as funções principais, como leitura do CSV, busca sequencial e medições de desempenho.



###  `include/`

Contém os arquivos de cabeçalho (.h), responsáveis por declarar funções e estruturas utilizadas no projeto, permitindo a modularização do código.


###  `arquivo/`

Armazena os arquivos de dados utilizados pelo programa, como o dataset em formato CSV.


###  `main.c`

Arquivo principal do programa, responsável por coordenar a execução geral, chamando as funções necessárias para leitura, processamento e análise dos dados.

### Visualizar os resultados

Os resultados serão gerados no arquivo:

```
resultado.txt
```
