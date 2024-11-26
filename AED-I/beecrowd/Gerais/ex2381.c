#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, K;
    char **nomes;

    // Lê os valores de N e K
    if (scanf("%d %d", &N, &K) != 2 || N < 1 || N > 100 || K < 1 || K > N) {
        fprintf(stderr, "Erro: Entrada inválida. Certifique-se de que 1 ≤ K ≤ N ≤ 100.\n");
        return 1;
    }

    // Aloca dinamicamente um array de ponteiros para os nomes
    nomes = (char **)malloc(N * sizeof(char *));
    if (nomes == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    // Lê os nomes e aloca memória para cada nome
    for (int i = 0; i < N; i++) {
        nomes[i] = (char *)malloc(21 * sizeof(char)); // Até 20 caracteres + '\0'
        if (nomes[i] == NULL) {
            fprintf(stderr, "Erro de alocação de memória.\n");
            return 1;
        }

        if (scanf("%20s", nomes[i]) != 1) { // Lê o nome com no máximo 20 caracteres
            fprintf(stderr, "Erro na leitura do nome.\n");
            return 1;
        }
    }

    // Ordena os nomes em ordem alfabética
    qsort(nomes, N, sizeof(char *), compara);

    // Exibe o K-ésimo nome (índice K-1 devido à indexação começar em 0)
    printf("%s\n", nomes[K - 1]);

    // Libera a memória alocada
    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
