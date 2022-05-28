#include <iostream>
#include <stdio.h>
unsigned __int64 contador_inicial, contador_final;

extern "C" {
    int add_vtr_asm(int*, int*, int*, int);
}

void add_vtr() {

    __declspec(align(16))
        int vetor1[65536];
    __declspec(align(16))
        int vetor2[65536];
    __declspec(align(16))
        int soma[65536];
    for (int i = 0; i <= 65535; i++) {
        vetor1[i] = i;
        vetor2[i] = i;
    }
    contador_inicial = __rdtsc();
    add_vtr_asm(vetor1, vetor2, soma, 65536);
    contador_final = __rdtsc();
    for (int i = 0; i <= 65535; i++) {
        printf("Soma[%d] = %d \n", i, soma[i]);
    }
    printf("Fun��o executada em %I64d ciclos de CPU", contador_final-contador_inicial);
    exit(0);
}

int main()
{

    printf("Programa para somar dois vetores de inteiros(32 bits): \n");
    printf("Soma de vetores com %d elementos \n", 65536);
    add_vtr();
}