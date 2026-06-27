#ifndef HASH_H
#define HASH_H

#include <stdio.h>

typedef struct Produto {
    int id;
    char nome[51];
    char categoria[31];
    float valor;
} Produto;

typedef struct No{
    struct No *proximo;
    struct Produto produto;
}No;

typedef struct Tabela_hash{
    No **no;
}Tabela_hash;

Tabela_hash * criar_tabela(); // criar a tabela hash
void colisoes(Tabela_hash *tabela, No *no, int hash); // Colisões encontradas na tabela
void montar_hash(Tabela_hash *tabela, FILE *arquivo); // preencher a tabela hash com todos os dados do arquivo.
No * buscar_hash(int id, Tabela_hash *tabela); // buscar e retorna o No do ID.

#endif