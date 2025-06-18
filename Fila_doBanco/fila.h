typedef struct {
    int inicio;
    int fim;
    int quantidade;
    int tamanho;
    char nomes[50][50];
} t_fila;

t_fila* criar_fila();
void enfileirar(t_fila* fila, char* nome);
int desenfileirar(t_fila* fila, char* nome);
int is_empty(t_fila* fila);
void liberar_fila(t_fila* fila);
