#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

static const char* p;

// Função recursiva de parser
static t_node* parse_node() {
    if (*p == '\0') return NULL;
    if (*p == '(') {
        p++;
        if (*p == ')') { p++; return NULL; }
        t_node* node = (t_node*)malloc(sizeof(t_node));
        node->value = *p++;
        node->left = NULL;
        node->right = NULL;

        if (*p == ',') {
            p++;
            node->left = parse_node();
        }
        if (*p == ',') {
            p++;
            node->right = parse_node();
        }
        if (*p == ')') {
            p++;
            return node;
        } else {
            free(node);
            return NULL;
        }
    }
    return NULL;
}

t_binary_tree* create_tree_from_text(const char* text) {
    if (!is_valid_expression(text)) return NULL;

    p = text;
    t_binary_tree* tree = (t_binary_tree*)malloc(sizeof(t_binary_tree));
    tree->root = parse_node();
    return tree;
}

void destroy_node(t_node* node) {
    if (!node) return;
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
}

void destroy_tree(t_binary_tree* tree) {
    if (tree) {
        destroy_node(tree->root);
        free(tree);
    }
}

void pre_order(t_node* node) {
    if (node) {
        printf("%c ", node->value);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node* node) {
    if (node) {
        in_order(node->left);
        printf("%c ", node->value);
        in_order(node->right);
    }
}

void post_order(t_node* node) {
    if (node) {
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->value);
    }
}

int height(t_node* node) {
    if (!node) return -1;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

t_node* find_node(t_node* node, char value) {
    if (!node) return NULL;
    if (node->value == value) return node;
    t_node* found = find_node(node->left, value);
    if (found) return found;
    return find_node(node->right, value);
}

void print_tree(t_node* node, int level) {
    if (node) {
        print_tree(node->right, level + 1);
        for (int i = 0; i < level; i++) printf("   ");
        printf("%c\n", node->value);
        print_tree(node->left, level + 1);
    }
}

int is_valid_expression(const char* text) {
    int count = 0;
    for (const char* c = text; *c; c++) {
        if (*c == '(') count++;
        else if (*c == ')') count--;
        if (count < 0) return 0;
    }
    return count == 0;
}
