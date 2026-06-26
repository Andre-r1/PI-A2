#include <stdio.h>
#include <windows.h>
#include "../../include/temporizador/tempo_execucao.h"

static LARGE_INTEGER inicio, fim, frequencia;

void iniciar_timer() {
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio);
}

double finalizar_timer() {
    QueryPerformanceCounter(&fim);

    double duracao = (double)(fim.QuadPart - inicio.QuadPart)
     / frequencia.QuadPart;

    return duracao;
}