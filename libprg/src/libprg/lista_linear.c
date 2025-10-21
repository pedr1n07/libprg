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
        lista->elementos = realloc(lista->elementos, sizeof(int) * lista->capacidade*2); // fazer tratamento do realloc
        lista->capacidade *=2;
    }
        if (lista->elementos) {
            if (lista->ordenada) {
                inserir_ordenada(lista, valor);
            }else inserir_nao_ordenada(lista, valor);
        }
}

void inserir_nao_ordenada(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir_ordenada(lista_linear_t *lista, int valor) {
    for (int i = lista->tamanho - 1; i >= 0; --i) {
        if (lista->elementos[i] < valor) {
            lista->elementos[i+1] = valor;
            break;
        }
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->tamanho++;
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

int limitar_posicao(lista_linear_t* lista, int posicao) {

    if (posicao > lista->tamanho) return lista->tamanho;
    if (posicao < 0) return 0;

}

// Remover elemento do início (como uma fila)
void remover_lista_l(lista_linear_t* lista, int valor) {

    int indice = buscar_lista_l(lista, valor);
    if (indice > -1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
    }
    // if (lista_vazia(lista)) {
    //
    // }
    // for (int i = 0; i < lista->tamanho - 1; ++i) {
    //     lista->elementos[i] = lista->elementos[i + 1];
    // }
    // lista->tamanho--;
}


void remover_da_posicao(lista_linear_t* lista, int posicao) {
    int valor = lista->elementos[posicao];
    remover_lista_l(lista, valor);
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


int buscar_na_posicao(lista_linear_t *lista, int posicao) {
    return lista->elementos[posicao];
}

void inserir_na_posicao(lista_linear_t* lista, int valor, int posicao) {

    int indice = limitar_posicao(lista, posicao);

    inserir_lista_l(lista, lista->elementos[indice]);
    lista->elementos[indice] = valor;
}
