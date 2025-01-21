#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 400000; //constante para tamanho do vetor

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    Quicksort(0, TAM, vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double

    return 0;
}