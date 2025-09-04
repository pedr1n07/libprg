#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha,int valor);
// int push(pilha_t* p, int valor);
int tamanho_pilha(pilha_t* p);
void destruir(pilha_t* pilha);



#endif
