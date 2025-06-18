
typedef struct t_node {
    char value;
    struct t_node *left;
    struct t_node *right;
} t_node;

typedef struct {
    t_node* root;
} t_binary_tree;

// Operações
t_binary_tree* create_tree_from_text(const char* text);
void destroy_tree(t_binary_tree* tree);

void pre_order(t_node* node);
void in_order(t_node* node);
void post_order(t_node* node);
int height(t_node* node);
t_node* find_node(t_node* node, char value);
void print_tree(t_node* node, int level);

int is_valid_expression(const char* text);

