//
// Created by aluno on 06/11/2025.
//
#include <libprg/libprg.h>


void bubble_sort(int array[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        int troca = 0;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                troca = 1;
            }
        }
        if (troca) break;
    }
}