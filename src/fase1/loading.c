#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/fase1/loading.h"

Carregar_produto *carregar_vetor(FILE *arquivo, int linhas){
    Carregar_produto *saida = (Carregar_produto *)malloc(linhas*sizeof(Carregar_produto));
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