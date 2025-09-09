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

#endif
