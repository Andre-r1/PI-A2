#include <stdio.h>
#include <stdlib.h>
#include "../../include/fase1/busca_sequencial.h"
#include "../../include/fase1/loading.h"

int *criar_vetor(Carregar_produto *vetor){
    int *ids = (int*)malloc(sizeof(int)*1000);

    for(int i = 0; i < 1000; i++){
        if( i < 750){
            ids[i] = (vetor +264*i)->id;
        } else {
            ids[i] = 2000000 +20*i;
        }
    }
    return ids;
}

int Busca_sequencial(Carregar_produto *vetor, int id, int linhas){   
    for(int i = 0; i < linhas; i++){
        if((vetor + i)->id == id){
            return i;
        } 
    }
        
    return -1;
}