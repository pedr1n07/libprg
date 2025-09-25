//
// Created by aluno on 25/09/2025.
//

#include <libprg/libprg.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;

}no_t;


no_t* criar_lista_enc(int valor) {

    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return  no;
}

no_t* adicionar_elemento(no_t* inicio, int valor) {

    no_t* novo_no = criar(valor);
    novo_no->proximo = inicio;
    inicio = novo_no;

    return inicio;

}

//criar
//adicionar