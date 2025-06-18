#include <stdio.h>
#include <stdlib.h>
#include "func.h"

t_stack* create_stack(int size) {
    t_stack* stack = (t_stack*)malloc(sizeof(t_stack));
    stack->size = size;
    stack->top = -1;
    stack->val = (int*)malloc(sizeof(int) * size);
    return stack;
}

void push(t_stack* stack, int value) {
    if (stack->top < stack->size - 1) {
        stack->val[++stack->top] = value;
    }
}

int pop(t_stack* stack) {
    if (stack->top >= 0) {
        return stack->val[stack->top--];
    }
    return -1;
}

int is_empty(t_stack* stack) {
    return stack->top == -1;
}

void free_stack(t_stack* stack) {
    free(stack->val);
    free(stack);
}
