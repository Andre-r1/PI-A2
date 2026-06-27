#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/fase1/loading.h"
#include "include/fase1/busca_sequencial.h"
#include "include/temporizador/tempo_execucao.h"
#include "include/fase2/hash.h"

int main(){

    double tempo_total, tempo_segmento, t;
    No* achou = malloc(sizeof(No));

    FILE *dataset = fopen("arquivo/dataset2.csv", "r"); 
    FILE *resultado = fopen("resultado_hash.txt", "w"); //arquivo de saída com os resultados


    iniciar_timer();
    Carregar_produto *vetor_produto = carregar_vetor(dataset, 200004); //montagem em vetor conforme fase 1
    t = finalizar_timer();

    fprintf(resultado, "Tempo utilizado para carregar em vetor: %.7f\n\n",t);
    rewind(dataset); // rewind do arquivo dataset para poder ser usado novamente

    int *ids = criar_vetor(vetor_produto); // Função criada para pesquisar os mesmo dados da fase1
    free(vetor_produto); // Evitar problema na fase 2


    Tabela_hash *tabela_hash = criar_tabela();

    iniciar_timer();
    montar_hash(tabela_hash, dataset); // Aplicando os dados do arquivo dataset na tabela hash
    t = finalizar_timer();

    fprintf(resultado, "Tempo calculado para carregar a tabela Hash: %.7f\n\n",t);

    
    

    fprintf(resultado, "\n As primeiras 250 pesquisas\n\n");

    for(int i = 0; i<250; i++){
        iniciar_timer();
        achou = buscar_hash(*(ids+i), tabela_hash);
        t = finalizar_timer();
        fprintf(resultado, "Tempo utilizado: %.7f\n\n", t);
        tempo_segmento += t;
        tempo_total += t;
    }

    fprintf(resultado, "\n O tempo utilizado nas primeiras 250 pesquisa foi de: %.7fs, Tempo médio: %.7fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    fprintf(resultado, "\n Segunda pesquisa 250 - 500\n\n");

    for(int i = 250; i<500; i++){
        iniciar_timer();
        achou = buscar_hash(*(ids+i), tabela_hash);
        t = finalizar_timer();
        fprintf(resultado, "Tempo utilizado: %.7f\n\n", t);
        tempo_segmento += t;
        tempo_total += t;
    }

    fprintf(resultado, "\n O tempo utilizado na segunda pesquisa foi de: %.7fs, Tempo médio: %.7fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    fprintf(resultado, "\n Terceira pesquisa 500 - 750\n\n");

    for(int i = 500; i<750; i++){
        iniciar_timer();
        achou = buscar_hash(*(ids+i), tabela_hash);
        t = finalizar_timer();
        fprintf(resultado, "Tempo utilizado: %.7f\n\n", t);
        tempo_segmento += t;
        tempo_total += t;
    }

    fprintf(resultado, "\n O tempo utilizado na terceira persquisa foi de: %.7fs, Tempo médio: %.7fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    fprintf(resultado, "\n Quarta pesquisa - Inexistentes\n\n");

    for(int i = 750; i<1000; i++){
        iniciar_timer();
        achou = buscar_hash(*(ids+i), tabela_hash);
        t = finalizar_timer();
        fprintf(resultado, "Tempo utilizado: %.7f\n\n", t);
        tempo_segmento += t;
        tempo_total += t;
    }

    fprintf(resultado, "\n O tempo utilizado na quarta pesquisa foi de: %.7fs, Tempo médio: %.7fs\n", tempo_segmento, tempo_segmento/250);
    
    
    fprintf(resultado, "\n O tempo total utilizado: %.7fs, Tempo médio total utilizado: %.7fs\n", tempo_total, tempo_total/1000);
  
    return 0;
}