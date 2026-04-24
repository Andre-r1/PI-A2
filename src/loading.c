#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/loading.h"

Produto *carregar_vetor(FILE *arquivo, int linhas){
    Produto *saida = (Produto *)malloc(linhas*sizeof(Produto));
    int c;
    
    
    while((c = fgetc(arquivo))!='\n'&&c!=EOF);
    for(int i = 0; i<(linhas);i++){
        if(fscanf(arquivo,"%d,%50[^,],%30[^,],%f,",
            &saida[i].id, 
            saida[i].nome, 
            saida[i].categoria, 
            &saida[i].valor)==EOF){
                break;
            };
    }

    return saida;
}