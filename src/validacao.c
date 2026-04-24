#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validacao.h"

void validar_vetor(Produto *vetor, int linhas){
    for(int i = 0; i < linhas; i++){

        if(vetor[i].id < 0)
            printf("ID inválido na linha %d\n", i+1);

        if(vetor[i].valor < 0)
            printf("Valor inválido na linha %d\n", i+1);
    }
}