#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Amigo {
    char nome[50];
    struct Amigo *proximo;
} Amigo;

void insere(Amigo **inicio, char *nomeAmigo);

int main() {
    char entrada[120];
    char delimitadores[] = " ";

    Amigo *listaDeAmigos = NULL;  // Ponteiro para o início da lista

    printf("Digite a lista de amigos: ");
    fgets(entrada, 120, stdin);

    char *resultado = strtok(entrada, delimitadores);
    while (resultado != NULL) {
        insere(&listaDeAmigos, resultado);  // Insere cada nome na lista
        resultado = strtok(NULL, delimitadores);
    }

    // Imprime a lista de amigos para verificar a inserção
    Amigo *temp = listaDeAmigos;
    while (temp != NULL) {
        printf("%s -> ", temp->nome);
        temp = temp->proximo;
    }
    printf("NULL\n");

    return 0;
}

void insere(Amigo **inicio, char *nomeAmigo) {
    Amigo *novoAmigo = (Amigo *)malloc(sizeof(Amigo));

    strcpy(novoAmigo->nome, nomeAmigo);
    novoAmigo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novoAmigo;
    } else {
        Amigo *temp = *inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoAmigo;
    }
}