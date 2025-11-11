#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// /--- pila---/
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p);
int topo_pilha(pilha_t* p);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);
int vazia_pilha(pilha_t *p);
int pilha_cheia(pilha_t *p);


// /---fila---/
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int tamanho_fila(fila_t* fila);
void enfileirar(fila_t* fila, int valor);
bool fila_cheia(fila_t* fila);
int desinfileirar(fila_t* fila);
bool vazia(fila_t* fila);
void destruir_fila(fila_t* fila);
void exibir(fila_t* fila);


// /---Lista Linear---/ //
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
bool lista_cheia (lista_linear_t* lista);
void inserir_lista_l(lista_linear_t* lista, int valor);
void inserir_nao_ordenada(lista_linear_t* lista, int valor);
void inserir_ordenada(lista_linear_t* lista, int valor);
int buscar_lista_l(lista_linear_t* lista, int valor);
bool lista_vazia(lista_linear_t* lista);
void remover_lista_l(lista_linear_t* lista, int valor);
void remover_da_posicao(lista_linear_t* lista, int posicao);
int primeiro_lista_l(lista_linear_t* lista);
void exibir_lista_l(lista_linear_t* lista);
void destruir_lista_l(lista_linear_t* lista);
int buscar_na_posicao(lista_linear_t *lista, int posicao);
void inserir_na_posicao(lista_linear_t* lista, int valor, int posicao);


// /---Listas Encadeada---/ //
typedef struct no no_t;
no_t* criar_lista_enc(int valor);
void adicionar_lista_enc(no_t** inicio, int valor);
no_t* buscar_lista_enc(no_t* inicio, int valor);
void remover_lista_enc(no_t** inicio, int valor);
void destruir_lista_enc(no_t** inicio);
void destruir_lista_enc_circular(no_t** inicio);



// /---Bubble sort---/ //
void bubble_sort(int array[], int tamanho);




#endif
