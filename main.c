#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/loading.h"
#include "include/tempo_execucao.h"
#include "include/busca_sequencial.h"
#include "include/validacao.h"

int main(){
    double tempo_total, tempo_atual, x;
    int achou;
    
    FILE *dataset = fopen("arquivo/dataset2.csv", "r");  // carrega o dataset2csv em modo de leitura
    FILE *resultado = fopen("resultado.txt", "w");  //abrir o arquivo txt
    Produto *produtos = carregar_vetor(dataset, 200004);  // roda a função para carregar o vetor a partir do csv
    validar_vetor(produtos, 200004); //validação do vetor

    
    int *ids = criar_vetor(produtos);

   
   
   // primeiras 250 pesquisas
    fprintf(resultado, "\n            Primeiras 250 pesquisas\n\n");

    for(int i = 0; i<250; i++){
        iniciar_timer(); // inicia o timer 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        x = finalizar_timer(); //finaliza o timer
        fprintf(resultado, "Tempo de execucao: %.9f, Linha no dataset: %i\n", x, achou);
        tempo_atual += x;
        tempo_total += x;
    }
   
    fprintf(resultado, "\n");
    fprintf(resultado, " O tempo de execucao da primeira parte: %.9fs\n Tempo médio: %.9fs\n", tempo_atual, tempo_atual/250);
    tempo_atual = 0;

    // Pesquisas 250 - 500
    fprintf(resultado, "\n            Pesquisas 250 - 500\n\n");

    for(int i = 250; i<500; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        x = finalizar_timer(); 
        fprintf(resultado, "Tempo de execução: %.9f, Linha no dataset: %i\n", x, achou);
        tempo_atual += x;
        tempo_total += x;
    }
   
    fprintf(resultado, "\n");
    fprintf(resultado, " O tempo de execucao da primeira parte: %.9fs\n Tempo médio: %.9fs\n", tempo_atual, tempo_atual/500);
    tempo_atual = 0;

    // Pesquisas 500 - 750
    fprintf(resultado, "\n            Pesquisas 500 - 750\n\n");

    for(int i = 500; i<750; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        x = finalizar_timer();
        fprintf(resultado, "Tempo de execução: %.9f, Linha no dataset: %i\n", x, achou);
        tempo_atual += x;
        tempo_total += x;
    }
   
    fprintf(resultado, "\n");
    fprintf(resultado, " O tempo de execução na leitura final do arquivo: %.9fs\n Tempo medio: %.9fs\n", tempo_atual, tempo_atual/500);
    tempo_atual = 0;

    // Pesquisas 750 - 1000
    fprintf(resultado, "\n            Pesquisas 750 - 1000\n\n");

    for(int i = 750; i<1000; i++){
        iniciar_timer(); 
        achou = Busca_sequencial(produtos, *(ids+i), 200004);
        x = finalizar_timer();
        fprintf(resultado, "Tempo de execução: %.6f, Linha no dataset: %i\n", x, achou);
        tempo_atual += x;
        tempo_total += x;
    }
   
    fprintf(resultado, "\n");
    fprintf(resultado, " O tempo de execução da busca inexistente: %.9fs\n Tempo médio: %.9fs\n", tempo_atual, tempo_atual/500);
    fprintf(resultado, " O tempo de execução total: %.9fs\n Tempo médio total: %.9fs\n", tempo_total, tempo_total/4);

    fclose(resultado); // fechar resultado.txt 
    fclose(dataset); // fecha o dataset2.csv

    //para compilar: gcc main.c src/*.c -lm -o a.out
    return 0;
}