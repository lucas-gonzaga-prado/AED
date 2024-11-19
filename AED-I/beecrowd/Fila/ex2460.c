#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int identificador;
    struct fila *prox;
} Fila;

void insere (int, Fila **, Fila **);

int main (){
    int tamanho;
    int entrada, retorno;
    Fila *s, *t;
    s = NULL;
    t = NULL;

    printf("");
    scanf("%d", &tamanho);

    printf("");
    do{
        scanf("%d", &entrada);
        insere(entrada, &s, &t);
    } while (retorno != 0);


}

void insere (int e, Fila **es, Fila **et){
    Fila *novo;
    novo = malloc(sizeof(Fila));

    novo->identificador = e;
    novo->prox = NULL;

    if(*et == NULL){
        *es = novo;
        *et = *es;
    }
    else{
        (*et)->prox = novo;
        *et = novo;
    }


}