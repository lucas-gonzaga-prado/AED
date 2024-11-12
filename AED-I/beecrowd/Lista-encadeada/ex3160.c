#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char palavra[15];
    struct nodo *prox;
} nodo;

nodo* criarNodo(char *palavra) {
    nodo* novoNodo = (nodo*)malloc(sizeof(nodo));
    strcpy(novoNodo->palavra, palavra);
    novoNodo->prox = NULL;
    return novoNodo;
}

void inserir(nodo** cabeca, char* palavra, char *condicao) {
    nodo* novoNodo = criarNodo(palavra);

    if (*cabeca == NULL) {
        *cabeca = novoNodo;
        return;
    }

    nodo* ultimo = *cabeca;
    nodo* anterior = NULL;

    if (condicao == NULL || strcmp(condicao, "nao") == 0 || strlen(condicao) == 0) {
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novoNodo;
    } else {
        while (ultimo != NULL && strcmp(ultimo->palavra, condicao) != 0) {
            anterior = ultimo;
            ultimo = ultimo->prox;
        }

        if (ultimo == NULL) {
            anterior->prox = novoNodo;
        } else if (anterior == NULL) {
            novoNodo->prox = *cabeca;
            *cabeca = novoNodo;
        } else {
            novoNodo->prox = ultimo;
            anterior->prox = novoNodo;
        }
    }
}

void exibirLista(nodo* cabeca) {
    nodo* temp = cabeca;
    while (temp != NULL) {
        printf("%s", temp->palavra);
        temp = temp->prox;
        if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void liberarLista(nodo* cabeca) {
    nodo* temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

int main() {
    char *nomes;
    char* token;
    char *condicao = NULL;
    nodo *Cabeca = NULL;

    for (int i = 0; i < 2; i++) {
        nomes = (char*)calloc(100, sizeof(char));
        fgets(nomes, 100, stdin);

        if (i == 1) {
            condicao = (char*)calloc(15, sizeof(char));
            fgets(condicao, 15, stdin);
            condicao[strcspn(condicao, "\n")] = '\0';
        }
        
        token = strtok(nomes, " \n");
        while (token != NULL) {
            inserir(&Cabeca, token, condicao);
            token = strtok(NULL, " \n");
        }

        free(nomes);
    }

    free(condicao);
    exibirLista(Cabeca);
    liberarLista(Cabeca);

    return 0;
}