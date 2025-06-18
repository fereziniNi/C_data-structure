#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main() {
    char linha[256];
    t_binary_tree* arvore = NULL;

    while (1) {
        printf("> ");
        if (!fgets(linha, 256, stdin)) break;
        linha[strcspn(linha, "\n")] = '\0';

        if (strncmp(linha, "create ", 7) == 0) {
            if (arvore) destroy_tree(arvore);
            arvore = create_tree_from_text(linha + 7);
            if (!arvore) {
                printf("invalid\n");
            }
        } else if (strcmp(linha, "print") == 0) {
            if (arvore) print_tree(arvore->root, 0);
        } else if (strcmp(linha, "pre") == 0) {
            if (arvore) {
                pre_order(arvore->root);
                printf("\n");
            }
        } else if (strcmp(linha, "in") == 0) {
            if (arvore) {
                in_order(arvore->root);
                printf("\n");
            }
        } else if (strcmp(linha, "post") == 0) {
            if (arvore) {
                post_order(arvore->root);
                printf("\n");
            }
        } else if (strncmp(linha, "height ", 7) == 0) {
            if (arvore) {
                char c = linha[7];
                t_node* n = find_node(arvore->root, c);
                if (n) printf("%d\n", height(n));
                else printf("Node not found\n");
            }
        } else if (strcmp(linha, "exit") == 0) {
            break;
        }
    }

    if (arvore) destroy_tree(arvore);
    return 0;
}
