#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    t_fila* fila_prioridade = criar_fila();
    t_fila* fila_geral = criar_fila();
    char letra, nome[100];
    int cont_prioridade = 0;

    while (1) {
        scanf(" %c", &letra);

        if (letra == 'f') break;

        if (letra == 'p') {
            scanf("%s", nome);
            enfileirar(fila_prioridade, nome);

        } else if (letra == 'g') {
            scanf("%s", nome);
            enfileirar(fila_geral, nome);

        } else if (letra == 's') {
            if (!is_empty(fila_prioridade) && cont_prioridade < 3) {
                desenfileirar(fila_prioridade, nome);
                printf("%s\n", nome);
                cont_prioridade++;
            } else if (!is_empty(fila_geral)) {
                desenfileirar(fila_geral, nome);
                printf("%s\n", nome);
                cont_prioridade = 0;
            } else if (!is_empty(fila_prioridade)) {
                desenfileirar(fila_prioridade, nome);
                printf("%s\n", nome);
                cont_prioridade = 1;
            }
        }
    }

    liberar_fila(fila_prioridade);
    liberar_fila(fila_geral);

    return 0;
}
