#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char caracter;
    struct no *proximo;
} No;

// Função para empilhar um elemento
No* empilhar(No *pilha, char valor) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    return NULL; // Retorna NULL em caso de erro na alocação
}

// Função para desempilhar um elemento
No* desempilhar(No **pilha) {
    No *remover = NULL;

    if (*pilha) {
        remover = *pilha;
        *pilha = remover->proximo;
    }
    return remover;
}

// Função para verificar se os parênteses estão balanceados
int forma_par(char f, char d) {
    switch (f) {
        case ')': return (d == '(');
        case ']': return (d == '[');
        case '}': return (d == '{');
        default: return 0; // Caso não seja esperado
    }
}

// Função para identificar se a expressão está bem formada
int identifica_formacao(char x[]) {
    int i = 0;
    No *remover, *pilha = NULL;

    while (x[i] != '\0') {
        // Se é um parêntese de abertura, empilha
        if (x[i] == '[' || x[i] == '(' || x[i] == '{') {
            pilha = empilhar(pilha, x[i]);
        } 
        // Se é um parêntese de fechamento, desempilha e verifica
        else if (x[i] == ']' || x[i] == ')' || x[i] == '}') {
            remover = desempilhar(&pilha);
            // Se a pilha estiver vazia ou o parêntese não corresponder, a expressão está mal formada
            if (remover == NULL || forma_par(x[i], remover->caracter) == 0) {
                free(remover); // Evitar vazamento de memória
                return 1; // Expressão mal formada
            }
            free(remover);
        }
        i++;
    }

    // Se ainda há elementos na pilha, a expressão está mal formada
    if (pilha != NULL) {
        return 1; // Expressão mal formada
    }
    return 0; // Bem formada
}

int main() {
    int n;
    char exp[1001];  // Tamanho da expressão pode ser maior, então ajustei para 1001

    // Leitura do número de expressões
    if (scanf("%d\n", &n) != 1) {
        return 1;
    }

    // Loop para ler e verificar cada expressão
    for (int i = 0; i < n; i++) {
        // Limpar buffer antes de ler a expressão
        if (fgets(exp, sizeof(exp), stdin) == NULL) {
            return 1;
        }
        
        // Remover o caractere de nova linha no final da string
        exp[strcspn(exp, "\n")] = '\0';

        // Verificar a formatação dos parênteses
        if (identifica_formacao(exp)) {
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
    }

    return 0;
}
