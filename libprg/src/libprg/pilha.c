#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;

} pilha_t;

pilha_t* criar_pilha(int capacidade) {

    //Criar a estrutura pilha e alocar memória
    pilha_t* p = malloc(sizeof(pilha_t));

    // Alocar memória para os elementos da pilha
    p->elementos = (int*) malloc(sizeof(int) * capacidade);

    //Definir os valores iniciais da pilha
    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

int push(pilha_t* p, int valor) {

    if (p->topo +1 >= p->capacidade) {
        printf("Não é possivel empilhar");
        return 1;
    }
    p->topo++;
    p->elementos[p->topo] = valor;

    return 0;
}

int tamnho_pilha(pilha_t* p) {
    return p->topo + 1;
}