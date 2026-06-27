#include <stdlib.h>
#include <stdio.h>
#include "../../include/fase2/hash.h"

int funcao_hash(int id){
   unsigned long int x = (unsigned long int)id * 31;
   return x % 200004;
}

Tabela_hash *criar_tabela(){
    Tabela_hash *h = (Tabela_hash*)malloc(sizeof(Tabela_hash));
    if(h == NULL){
        return NULL;
    }
    h->no = (No**)calloc(200004, sizeof(No*));
    return h;
}

void colisoes(Tabela_hash *tabela, No *no, int hash){
    No *aux = tabela->no[hash];
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = no;
}

void montar_hash(Tabela_hash *tabela, FILE *arquivo){
    No buffer; // Usando variável local para evitar ponteiro solto
    int c;
    int k = 0;
    
    while((c = fgetc(arquivo)) != '\n' && c != EOF);

    while(fscanf(arquivo, "%d,%50[^,],%30[^,],%f\n",
        &buffer.produto.id, 
        buffer.produto.nome, 
        buffer.produto.categoria, 
        &buffer.produto.valor) == 4){

            int hash = funcao_hash(buffer.produto.id);
            No *novo = (No*)malloc(sizeof(No));
            if(novo == NULL) return; // Proteção de memória
            
            novo->produto = buffer.produto;

            if(tabela->no[hash] == NULL){
                novo->proximo = NULL;
                tabela->no[hash] = novo; 
            } else {
                novo->proximo = tabela->no[hash];
                tabela->no[hash] = novo;
                k++; // Conta a colisão
            }
    }
    
    printf("\n Colisoes = %i\n", k);
}


No * buscar_hash(int id, Tabela_hash *tabela){
    int hash = funcao_hash(id);

    if(tabela->no [hash] == NULL){
        return NULL;
    }

    No *novo = tabela->no [hash];

    while((id != novo->produto.id) && (novo->proximo != NULL)){
        novo = novo->proximo;
    }

    if(novo->produto.id != id){
        return NULL;
    }

    return novo;
}