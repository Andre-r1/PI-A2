# Análise Comparativa de Busca Sequencial e Tabela Hash
 
Projeto da disciplina de **Algoritmos e Estruturas de Dados** — Centro Universitário IESB.
 
Implementação e análise experimental de busca sequencial (Fase I) e tabela hash (Fase II) sobre um vetor dinâmico carregado a partir de um arquivo CSV com 200.004 registros de produtos.
 
---
 
## 👥 Integrantes
 
| Nome | Matrícula |
|---|---|
| Marcos Vinícius de Almeida Mendes | 2412130059 |
| André Souza Mattos | 2422130024 |
| Luiz Felipe Borges Pinho | 2412130056 |
 
---
 
## 📁 Estrutura do Projeto
 
```
PI-A2/
├── arquivo/
│   └── dataset2.csv        # Dataset com 200.004 registros
├── include/
│   ├── busca_sequencial.h  # Protótipos de busca e geração de IDs
│   ├── loading.h           # Protótipo de carregamento do CSV
│   ├── tempo_execucao.h    # Protótipo do temporizador
│   └── validacao.h         # Protótipo de validação do vetor
├── src/
│   ├── busca_sequencial.c  # Busca sequencial e geração de IDs de teste
│   ├── loading.c           # Leitura e carregamento do CSV
│   ├── tempo_execucao.c    # Temporizador com QueryPerformanceCounter
│   └── validacao.c         # Validação dos registros carregados
├── main.c                  # Programa principal e protocolo de testes
├── resultado.txt           # Saída gerada após a execução
└── README.md
```
 
---
 
## 🧩 Estrutura de Dados
 
```c
typedef struct {
    int   id;
    char  nome[51];
    char  categoria[31];
    float valor;
} Produto;
```
 
---
 
## ⚙️ Como Compilar e Executar
 
> **Requisito:** Windows com GCC (MinGW). O temporizador utiliza `QueryPerformanceCounter` da API do Windows.
 
### Fase I — Busca Sequencial
 
**Compilar:**
```bash
gcc main1.c src/fase1/busca_sequencial.c src/fase1/loading.c src/fase1/validacao.c src/temporizador/tempo_execucao.c -o a.exe
```
 
**Executar:**
```bash
./a.exe
```
 
Os resultados serão salvos automaticamente em `resultado.txt`.
 
### Fase II — Tabela Hash
 
**Compilar:**
```bash
gcc main2.c src/fase1/loading.c src/fase1/busca_sequencial.c src/temporizador/tempo_execucao.c src/fase2/hash.c -o resultado_hash.exe
```
 
**Executar:**
```bash
./resultado_hash.exe
```
 
---
 
## 📊 Fase I — Busca Sequencial
 
### Protocolo Experimental
 
O programa realiza **1.000 buscas** distribuídas em 4 grupos de 250:
 
| Grupo | Buscas | Descrição |
|---|---|---|
| Grupo 1 | 1 – 250 | Elementos do início do vetor |
| Grupo 2 | 251 – 500 | Elementos do meio do vetor |
| Grupo 3 | 501 – 750 | Elementos do final do vetor |
| Grupo 4 | 751 – 1000 | Elementos inexistentes |
 
### Resultados
 
| Tipo de Busca | Tempo Médio (s) |
|---|---|
| Início | 0,000098081 |
| Meio | 0,000302570 |
| Final | 0,000852383 |
| Inexistente | 0,000873186 |
| **Tempo Total** | **1,038589300 s** |
| **Tempo Médio Geral** | **0,259647325 s** |
 
### Análise
 
Os resultados confirmam o comportamento linear da busca sequencial, cuja complexidade é **O(n)**. Observa-se um crescimento progressivo no tempo médio conforme a posição do elemento no vetor:
 
- **Início** (0,024520200 s) → menor tempo
- **Meio** (0,151284900 s)
- **Final** (0,426191400 s)
- **Inexistente** (0,436592800 s) → pior caso
Isso ocorre porque o algoritmo percorre o vetor elemento por elemento até encontrar o valor ou chegar ao final. Conclui-se que a busca sequencial é pouco eficiente para grandes volumes de dados.
 
---
 
## 📊 Fase II — Tabela Hash
 
### Função Hash
 
A função hash definida para o grupo é:
 
```
h(x) = (x * 31) % m
```
 
onde `x` é o id do registro e `m = 200.004` é o tamanho da tabela.
 
### Protocolo Experimental
 
O programa realiza **1.000 buscas** distribuídas em 4 grupos de 250, com a tabela hash completamente carregada antes das medições:
 
| Grupo | Buscas | Descrição |
|---|---|---|
| Grupo 1 | 1 – 250 | Elementos do início do dataset |
| Grupo 2 | 251 – 500 | Elementos do meio do dataset |
| Grupo 3 | 501 – 750 | Elementos do final do dataset |
| Grupo 4 | 751 – 1000 | Elementos inexistentes |
 
### Resultados
 
| Grupo | Tempo Total (s) | Tempo Médio (s) |
|---|---|---|
| Início | 0,000107200 | 0,000000429 |
| Meio | 0,000137800 | 0,000000551 |
| Fim | 0,000156100 | 0,000000624 |
| Inexistente | 0,000107000 | 0,000000428 |
| **Total** | **0,000508100** | **0,000000508** |
 
- **Colisões:** 0
- **Tempo de montagem do vetor:** 0,255672600 s
- **Tempo de montagem da tabela hash:** 0,357399400 s
---
 
## 📈 Comparativo — Fase I vs Fase II
 
| Métrica | Busca Sequencial | Tabela Hash |
|---|---|---|
| Tempo médio por busca (s) | 0,001038589 | 0,000000508 |
| Complexidade teórica | O(n) | O(1) amortizado |
| Total de colisões | N/A | 0 |
| Tempo de montagem (s) | 0,255672600 | 0,357399400 |
| Registros carregados | 200.004 | 200.004 |
 
A tabela hash foi aproximadamente **2.044 vezes mais rápida** que a busca sequencial. O zero colisões indica que a função hash `h(x) = (x * 31) % m` distribuiu perfeitamente os 200.004 ids nas posições da tabela.
 
---
 
## 📄 Licença
 
Distribuído sob a licença Apache 2.0. Veja o arquivo `LICENSE` para mais detalhes.
 
