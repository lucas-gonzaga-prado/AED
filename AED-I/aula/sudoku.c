#include <stdio.h>

int jogo[9][9];

int verificaLinha(int);
int verificaColuna(int);
int verificaQuadrado(int);
void imprime();
void preenche();

int main(){
    int linha, coluna;
    char* resposta;

    preenche();

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            imprime();
            printf("\nCoordenada (L C): ");
            scanf("%d %d", &linha, &coluna);

            printf("\nN: ");
            scanf("%d", &jogo[linha][coluna]);
        }
    }

    resposta = "SIM";

    for(int i = 0; i < 9; i++){
        if(!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)){
            resposta = "NAO";
            break;
        }
    }

    printf("%s\n", resposta);
    return 0;
}

int verificaLinha(int t){
    int linhas[10] = {0};

    for(int i = 0; i < 9; i++){
        if(linhas[jogo[t][i]])
            return 0;
        linhas[jogo[t][i]] += 1;
    }
    return 1;
}

int verificaColuna(int t){
    int colunas[10] = {0};

    for(int i = 0; i < 9; i++){
        if(colunas[jogo[i][t]])
            return 0;
        colunas[jogo[i][t]] += 1;
    }
    return 1;
}

int verificaQuadrado(int t){
    int quadrado[10] = {0};
    int linha = 3 * (t / 3), coluna = 3 * (t % 3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(quadrado[jogo[linha + i][coluna + j]])
                return 0;
            quadrado[jogo[linha + i][coluna + j]] += 1;
        }
    }

    return 1;
}

void imprime (){
    for(int i = 0; i < 9; i++){
        printf("\n");
        for(int j = 0; j < 9; j++){
            if(jogo[i][j] == 0)
                printf("%3c", '*');  // Exibe '*' se o valor for 0
            else
                printf("%3d", jogo[i][j]);  // Exibe o número se for diferente de 0
        }
    }
    printf("\n");
}

void preenche (){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            jogo[i][j] = 0;  // Preenche com 0, representando uma célula vazia
        }
    }
}