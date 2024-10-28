#include <stdio.h>

// Tabuleiro como variável global
int jogo[9][9];

int verificaLinha(int);
int verificaColuna(int);
int verificaQuadrado(int);

int main(){
    int entrada;
    char* resposta;

    // Entrada controla as instâncias (partidas) que o código vai verificar
    scanf("%d", &entrada);

    // Preenchendo a tabela do jogo
    for(int k = 1; k <= entrada; k++){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &jogo[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        // Até que se encontre um erro, o jogo é considerado válido
        resposta = "SIM";

        // Verificação da validade do jogo
        for(int i = 0; i < 9; i++){
            if(!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)){
                resposta = "NAO";
                break;
            }
        }

        printf("%s\n\n", resposta);
    }

    return 0;
}

int verificaLinha(int t){
    // Vetor para contar os números nos índices correspondentes; se houver repetição, retorna 0
    int linhas[10] = {0};

    for(int i = 0; i < 9; i++){
        if(linhas[jogo[t][i]])  // Se o número já apareceu, retorna 0
            return 0;
        linhas[jogo[t][i]] += 1;  // Marca o número como visto
    }
    return 1;
}

int verificaColuna(int t){
    // Vetor para contar os números nos índices correspondentes; se houver repetição, retorna 0
    int colunas[10] = {0};

    for(int i = 0; i < 9; i++){
        if(colunas[jogo[i][t]])  // Se o número já apareceu, retorna 0
            return 0;
        colunas[jogo[i][t]] += 1;  // Marca o número como visto
    }
    return 1;
}

int verificaQuadrado(int t){
    // Vetor para contar os números nos índices correspondentes no bloco 3x3; se houver repetição, retorna 0
    int quadrado[10] = {0};
    int linha = 3 * (t / 3), coluna = 3 * (t % 3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(quadrado[jogo[linha + i][coluna + j]])  // Se o número já apareceu, retorna 0
                return 0;
            quadrado[jogo[linha + i][coluna + j]] += 1;  // Marca o número como visto
        }
    }

    return 1;
}
