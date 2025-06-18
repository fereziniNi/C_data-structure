#ifndef FUNC_H
#define FUNC_H

typedef struct {
    int top;
    int size;
    int* val;
} t_stack;

t_stack* create_stack(int capacity);
void push(t_stack* stack, int val);
int pop(t_stack* stack);
int is_empty(t_stack* stack);
void free_stack(t_stack* stack);
void trocas(int* a, int* b);
int newLista(int lista[], int min, int max);
void quick_sort(int lista[], int n);

#endif
