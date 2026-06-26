#ifndef LOADING_H
#define LOADING_H

#include <stdio.h>

typedef struct produto_t {
int id;
char nome[51];
char categoria[31];
float valor;
} Carregar_produto; // estrutura do vetor do csv


Carregar_produto *carregar_vetor(FILE *arquivo, int linhas); //função para organizar o dataset2.csv em um vetor da estrutura Produto


#endif