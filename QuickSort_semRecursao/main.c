#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int newLista(int lista[], int min, int max) {
    int pivo = lista[max];
    int i = min - 1;
    for (int j = min; j < max; j++) {
        if (lista[j] <= pivo) {
            i++;
            trocas(&lista[i], &lista[j]);
        }
    }
    trocas(&lista[i + 1], &lista[max]);
    return i + 1;
}

void trocas(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int lista[], int n) {
    t_stack* stack = create_stack(n);

    push(stack, 0);
    push(stack, n - 1);

    while (!is_empty(stack)) {
        int max = pop(stack);
        int min = pop(stack);
        
        if (min >= max) continue;
        
        int p = newLista(lista, min, max);

        if (p - 1 > min) {
            if (p - min < max - p) {
                push(stack, min);
                push(stack, p - 1);
            } else {
                push(stack, p);
                push(stack, max);
                push(stack, min);
                push(stack, p - 1);
            }
        }
        if (p + 1 < max) {
            if (max - p < p - min) {
                push(stack, p + 1);
                push(stack, max);
            } else {
                push(stack, min);
                push(stack, p - 1);
                push(stack, p + 1);
                push(stack, max);
            }
        }
    }

    free_stack(stack);
}

int main() {
    int n;
    printf("Insira a quantidade de elementos: ");
    scanf("%d", &n);
    int* lista = (int*)malloc(n * sizeof(int));

    printf("Insira todos os elem: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
    
    quick_sort(lista, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    
    free(lista);
    return 0;
}
