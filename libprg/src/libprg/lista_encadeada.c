//
// Created by aluno on 25/09/2025.
//

#include <libprg/libprg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

// Cria um novo nó com valor
no_t* criar_lista_enc(int valor) {
    no_t* no = malloc(sizeof(no_t));
    if (!no) return NULL;

    no->valor = valor;
    no->proximo = NULL;
    return no;
}

// Insere no início da lista
void adicionar_lista_enc(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_enc(valor);
    if (!novo_no) return;

    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

// Busca por valor
no_t* buscar_lista_enc(no_t* inicio, int valor) {
    no_t* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Remove um nó com valor específico
void remover_lista_enc(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                // Removendo o primeiro nó
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return; // Para após remover
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

// Libera toda a lista
void destruir_lista_enc(no_t** inicio) {
    no_t* atual = *inicio;

    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

void destruir_lista_enc_circular(no_t** inicio) {
    no_t* atual = *inicio;

    while (atual) {
        no_t* proximo = atual->proximo;
        free(atual);
        if (proximo == *inicio) break;
        atual = proximo;
    }
}

//criar
//adicionar