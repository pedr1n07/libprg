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


no_t* criar_lista_enc(int valor) {

    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return  no;
}

void adicionar_lista_enc(no_t** inicio, int valor) {

    no_t* novo_no = criar_lista_enc(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;

}

no_t* buscar_lista_enc(no_t** inicio, int valor) {

    no_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }else {
            atual = atual->proximo;
        }
    }
    return NULL;
}

void remover_lista_enc(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual) {
        if (atual->valor == valor) {

            anterior->proximo = atual->proximo;
        }
    }
    free(atual);
}

void destruir_lista_enc(no_t** inicio) {

    no_t* atual = *inicio;

    while (atual) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
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