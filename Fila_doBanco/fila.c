#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

t_fila* criar_fila() {
    t_fila* fila = (t_fila*)malloc(sizeof(t_fila));
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 50;
    fila->quantidade = 0;
    return fila;
}

void enfileirar(t_fila* fila, char* nome) {
    if (fila->quantidade == fila->tamanho) return;
    fila->fim = (fila->fim + 1) % fila->tamanho;
    strcpy(fila->nomes[fila->fim], nome);
    fila->quantidade++;
}

int desenfileirar(t_fila* fila, char* nome) {
    if (esta_vazia(fila)) return 0;
    strcpy(nome, fila->nomes[fila->inicio]);
    fila->inicio = (fila->inicio + 1) % fila->tamanho;
    fila->quantidade--;
    return 1;
}

int is_empty(t_fila* fila) {
    return fila->quantidade == 0;
}

void liberar_fila(t_fila* fila) {
    free(fila);
}
