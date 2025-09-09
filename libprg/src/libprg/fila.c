//
// Created by aluno on 09/09/2025.
//
#include <stdbool.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct fila {
    int inicio;
    int* elementos;
    int tamanho;
    int capacidade;
    int fim;
} fila_t;

fila_t* criar_fila(int capacidade) {

    fila_t* f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeof(int));

    f->inicio = 0;
    f->fim = 0;
    f->elementos = 0;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t* fila, int valor) {

    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim++;
    fila->tamanho++;
}

bool cheia(fila_t* fila) {
    return fila->tamanho >= fila->capacidade;
}


int desinfileirar(fila_t* fila) {
    return fila->elementos[fila->inicio];
    fila->inicio++;
}

bool vazia(fila_t* fila) {
    return fila->tamanho == 0;
}










// criar_fila
// enfilherrar
// desenfilerar
// inicio
// fim
// tamanho
// vazia
// destruir_fila