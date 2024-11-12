#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento
{
  char nome[21];
  struct elemento *proximo;
};

struct elemento *adicionar_novo_elemento(char nome[21])
{
  struct elemento *novo_elemento = malloc(sizeof(struct elemento));
  strncpy(novo_elemento->nome, nome, 20);
  novo_elemento->proximo = NULL;
  return novo_elemento;
}

struct elemento *encontrar_ultimo_elemento(struct elemento *inicio)
{
  struct elemento *ultimo = inicio;
  while (ultimo->proximo != NULL)
  {
    ultimo = ultimo->proximo;
  }
  return ultimo;
}

void remover_elemento(struct elemento *inicio, struct elemento *lixo)
{
  struct elemento *anterior = inicio;
  while (anterior->proximo != lixo)
  {
    anterior = anterior->proximo;
  }
  anterior->proximo = lixo->proximo;
  free(lixo);
}

void limpar_lista(struct elemento *inicio)
{
  struct elemento *atual = inicio->proximo;
  while (atual != NULL)
  {
    struct elemento *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
  inicio->proximo = NULL;
}

void imprimir_elementos(struct elemento *inicio)
{
  struct elemento *atual = inicio->proximo;
  bool primeiro = true;
  while (atual != NULL)
  {
    if (!primeiro)
      printf(" ");
    printf("%s", atual->nome);
    primeiro = false;
    atual = atual->proximo;
  }
  printf("\n");
}

bool verificar_unicidade(struct elemento *inicio, char nome[21])
{
  struct elemento *atual = inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->nome, nome) == 0)
      return false;
    atual = atual->proximo;
  }
  return true;
}

void ordenar_lista(struct elemento *inicio)
{
  if (inicio == NULL || inicio->proximo == NULL)
    return;

  bool ordenado = false;
  while (!ordenado)
  {
    ordenado = true;
    struct elemento *anterior = inicio;
    struct elemento *atual = inicio->proximo;

    while (atual != NULL && atual->proximo != NULL)
    {
      if (strcmp(atual->nome, atual->proximo->nome) > 0)
      {
        struct elemento *temp = atual->proximo;
        atual->proximo = temp->proximo;
        temp->proximo = atual;
        anterior->proximo = temp;

        ordenado = false;
        anterior = temp;
      }
      else
      {
        anterior = atual;
        atual = atual->proximo;
      }
    }
  }
}

int main()
{
  int n;

  struct elemento cabeca;
  strcpy(cabeca.nome, "Cabeca");
  cabeca.proximo = NULL;
  struct elemento *pCabeca = &cabeca;

  do
  {
    scanf("%d", &n);
  } while (n <= 0 || n > 100);

  getchar();
  for (int i = 0; i < n; i++)
  {
    char texto[21000] = {0};
    fgets(texto, sizeof(texto) - 1, stdin);
    int tamanho_texto = strlen(texto);
    int contador_palavra = 0;
    limpar_lista(pCabeca);

    for (int j = 0; j < tamanho_texto; j++)
    {
      if (texto[j] == ' ' || texto[j] == '\0' || texto[j] == '\n')
      {
        if (contador_palavra > 0)
        {
          char palavra[21] = {0};
          for (int z = 0; z < contador_palavra; z++)
          {
            palavra[z] = texto[j - contador_palavra + z];
          }
          palavra[contador_palavra] = '\0';
          if (verificar_unicidade(pCabeca, palavra))
          {
            struct elemento *novo = adicionar_novo_elemento(palavra);
            struct elemento *ultimo = encontrar_ultimo_elemento(pCabeca);
            ultimo->proximo = novo;
          }
          contador_palavra = 0;
        }
      }
      else
      {
        contador_palavra++;
      }
    }
    ordenar_lista(pCabeca);
    imprimir_elementos(pCabeca);
  }

  return 0;
}
