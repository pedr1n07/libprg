//
// Created by aluno on 18/09/2025.
//

#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

// Função para criar a lista
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    if (!lista) return NULL;

    lista->elementos = malloc(sizeof(int) * capacidade);
    if (!lista->elementos) {
        free(lista);
        return NULL;
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
    return lista;
}

bool lista_cheia(lista_linear_t* lista) {
    return lista->tamanho == lista->capacidade;
}

bool lista_vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

// Inserir elemento no final
void inserir_lista_l(lista_linear_t* lista, int valor) {
    if (lista_cheia(lista)) {
        printf("Erro: lista cheia, não é possível inserir.\n");
        return;
    }
    lista->elementos[lista->tamanho++] = valor;
}

// Buscar elemento
int buscar_lista_l(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1; // não encontrado
}

// Remover elemento do início (como uma fila)
void remover_lista_l(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        printf("Erro: lista vazia, não é possível remover.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho - 1; ++i) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
}

// Retornar o primeiro elemento
int primeiro_lista_l(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        printf("Erro: lista vazia.\n");
        return -1;
    }
    return lista->elementos[0];
}

// Exibir lista
void exibir_lista_l(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

// Destruir lista
void destruir_lista_l(lista_linear_t* lista) {
    if (lista) {
        free(lista->elementos);
        free(lista);
    }
}
