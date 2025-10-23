#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;

} pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* p = malloc(sizeof(pilha_t));
    if (p == NULL) return NULL;

    p->elementos = malloc(capacidade * sizeof(int));
    if (p->elementos == NULL) {
        free(p);
        return NULL;
    }

    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

int empilhar(pilha_t* p, int valor) {
    if (p->topo >= p->capacidade - 1)
        return 0; // pilha cheia

    p->elementos[++(p->topo)] = valor;
    return 1;
}

int desempilhar(pilha_t* p) {
    if (p->topo < 0)
        return 0; // pilha vazia

    int elemento_removido = p->elementos[p->topo];
    p->topo = p->topo - 1;
    return elemento_removido;
}

int topo_pilha(pilha_t* p) {
    if (p->topo < 0)
        return 0;

    int topo = p->elementos[p->topo];
    return topo;
}

int tamanho_pilha(pilha_t* p) {
    return p->topo + 1;
}

void imprimir_pilha(pilha_t* p) {
    if (p->topo < 0) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha (base -> topo): ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

void destruir_pilha(pilha_t* p) {
    if (p) {
        free(p->elementos);
        free(p);
    }
}

int vazia_pilha(pilha_t *p) {
    if (p == NULL)
        return 1;
    return (p->topo < 0);

}

int pilha_cheia(pilha_t *p) {
    if (p == NULL)
        return 0;
    return (p->topo >= p->capacidade - 1);
}

// int push(pilha_t* p, int valor) {
//
//     if (p->topo +1 >= p->capacidade) {
//         printf("Não é possivel empilhar");
//         return 1;
//     }
//     p->topo++;
//     p->elementos[p->topo] = valor;
//
//     return 0;
// }


