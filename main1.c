#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/fase1/loading.h"
#include "include/temporizador/tempo_execucao.h"
#include "include/fase1/busca_sequencial.h"
#include "include/fase1/validacao.h"

int main(){
    
    srand(42); // Garante que a "aleatoriedade" seja idêntica nas duas mains!

    
    double tempo_total = 0, tempo_segmento = 0, y = 0; 
    int achou = 0; 
    
    FILE *dataset = fopen("arquivo/dataset2.csv", "r");  // carrega o dataset2csv in modo de leitura
    FILE *resultado = fopen("resultado.txt", "w");  //abrir o arquivo txt
    Carregar_produto *produtos = carregar_vetor(dataset, 200004);  // roda a função para carregar o vetor a partir do csv
    validar_vetor(produtos, 200004); //validação do vetor

    int *ids = criar_vetor(produtos);

    // primeiras 250 pesquisas
    fprintf(resultado, "\n            Primeiras 250 pesquisas\n\n");

    for(int i = 0; i<250; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        y = finalizar_timer(); 
        fprintf(resultado, "Tempo de execução: %.9f, Linha no dataset: %i\n", y, achou);
        tempo_segmento += y;   
        tempo_total += y;
    }
   
    fprintf(resultado, "\n");

    fprintf(resultado, " O tempo de execução na leitura da primeira parte arquivo: %.9fs\n Tempo médio: %.9fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    // Pesquisas 250 - 500
    fprintf(resultado, "\n            Pesquisas 250 - 500\n\n");

    for(int i = 250; i<500; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        y = finalizar_timer(); 
        fprintf(resultado, "Tempo de execução: %.9f, Linha no dataset: %i\n", y, achou);
        tempo_segmento += y;
        tempo_total += y;
    }
   
    fprintf(resultado, "\n");

    fprintf(resultado, " O tempo de execução na leitura da segunda parte do arquivo: %.9fs\n Tempo médio: %.9fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    // Pesquisas 500 - 750
    fprintf(resultado, "\n            Pesquisas 500 - 750\n\n");

    for(int i = 500; i<750; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        y = finalizar_timer();
        fprintf(resultado, "Tempo de execução: %.9f, Linha no dataset: %i\n", y, achou);
        tempo_segmento += y;
        tempo_total += y;
    }
   
    fprintf(resultado, "\n");
    // CORREÇÃO: Divisão por 250
    fprintf(resultado, " O tempo de execução na leitura final do arquivo: %.9fs\n Tempo medio: %.9fs\n", tempo_segmento, tempo_segmento/250);
    tempo_segmento = 0;

    // Pesquisas 750 - 1000
    fprintf(resultado, "\n            Pesquisas 750 - 1000\n\n");

    for(int i = 750; i<1000; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        y = finalizar_timer();
        fprintf(resultado, "Tempo de execução: %.6f, Linha no dataset: %i\n", y, achou);
        tempo_segmento += y;
        tempo_total += y;
    }
   
    fprintf(resultado, "\n");
    
    fprintf(resultado, " O tempo de execução da busca inexistente: %.9fs\n Tempo médio: %.9fs\n", tempo_segmento, tempo_segmento/250);
    fprintf(resultado, " O tempo de execução total: %.9fs\n Tempo médio total: %.9fs\n", tempo_total, tempo_total/1000);

    fclose(resultado); // fechar resultado.txt 
    fclose(dataset); // fecha o dataset2.csv

    return 0;
}