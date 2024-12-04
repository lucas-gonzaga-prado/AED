#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 350000; // constante para tamanho do vetor

void insertionSort(int v[TAM], int n) {
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        // Move elementos maiores que a chave
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];
    double tempos[5], soma_tempos = 0;

    srand((unsigned)time(NULL)); // semente de aleatoriedade

    for (int teste = 0; teste < 5; teste++) {
        // Geração aleatória dos valores do vetor
        for (int i = 0; i < TAM; i++)
            vetor[i] = rand() % TAM;

        // Medindo o tempo de execução do insertion sort
        t = clock();
        insertionSort(vetor, TAM);
        t = clock() - t;

        // Calcula tempo em milissegundos
        tempos[teste] = ((double)t) / (CLOCKS_PER_SEC / 1000);
        soma_tempos += tempos[teste];

        // Imprime o tempo do teste atual
        printf("Teste %d: Tempo de execucao: %lf ms\n", teste + 1, tempos[teste]);
    }

    // Calcula e imprime a média dos tempos
    double media = soma_tempos / 5;
    printf("Media dos tempos de execucao: %lf ms\n", media);

    return 0;
}
