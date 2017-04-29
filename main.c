/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tassio
 *
 * Created on 1 de Abril de 2017, 14:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10], fim;

void heapSort(int *a, int n) {
    int i = n / 2, pai, filho, t;
    for (;;) {
        if (i > 0) {
            i--;
            t = a[i];
        } else {
            n--;
            if (n == 0) return;
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
                filho++;
            if (a[filho] > t) {
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        a[pai] = t;
    }
}

int main(int argc, char** argv) {

    srand(time(NULL));
    for (int t = 0; t <= 10; t++) {
        a[t] = rand() % 10;
    }

    printf("Entrada = ");
    for (int t = 0; t <= 10; t++) {
        printf("%d ", a[t]);
    }
    fim = 12;
    printf("\nOdenação= ");
    heapSort(a, fim);
    for (int t = 0; t <= 10; t++) {
        printf("%d ", a[t]);
    }

    return (EXIT_SUCCESS);
}


