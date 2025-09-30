#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

// /--- pila---/
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha,int valor);
// int push(pilha_t* p, int valor);
int tamanho_pilha(pilha_t* p);
void destruir(pilha_t* pilha);



// /---fila---/
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool cheia(fila_t* fila);
int desinfileirar(fila_t* fila);
bool vazia(fila_t* fila);
void destruir_fila(fila_t* fila);
void exibir(fila_t* fila);


// /---Lista Linear---/ //
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar(int capacidade);
bool lista_cheia (lista_linear_t* lista);
void inserir(lista_linear_t* lista, int valor);
int buscar(lista_linear_t* lista, int valor);
bool lista_vazia(lista_linear_t* lista);
void remover(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);
void exibir_lista(lista_linear_t* lista);
int primeiro(lista_linear_t* lista);


// /---Listas Encadeada---/ //
typedef struct no no_t;
no_t* criar_lista_enc(int valor);
void adicionar_lista_enc(no_t** inicio, int valor);
no_t* buscar_lista_enc(no_t** inicio, int valor);
void remover_lista_enc(no_t** inicio, int valor);

#endif
