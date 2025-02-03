#include <stdio.h>

int main() {
    int n, i;

    // Leitura do número de termos da sequência
    scanf("%d", &n);

    // Declaração do vetor para armazenar os valores
    unsigned long int fatorial[n];

    // Definição dos primeiros termos da sequência
    fatorial[0] = 0;
    fatorial[1] = 1;

    // Preenchimento do vetor com a sequência
    for (i = 2; i < n; i++) {
        fatorial[i] = fatorial[i - 1] + fatorial[i - 2];
    }

    // Impressão dos valores gerados
    for (i = 0; i < n; i++) {
        if (i < n - 1)
            printf("%lu ", fatorial[i]);
        else
            printf("%llu\n", fatorial[i]);
    }

    return 0;
}
