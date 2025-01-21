#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Estrutura para armazenar pares de coordenadas (i, j)
typedef struct {
    int x, y;
} Pair;

// Função para verificar se uma posição já foi visitada
bool wasVisited(Pair visited[], int count, Pair pos) {
    for (int i = 0; i < count; i++) {
        if (visited[i].x == pos.x && visited[i].y == pos.y) {
            return true;
        }
    }
    return false;
}

int main() {
    int rows, columns;
    scanf("%d %d", &columns, &rows);

    char map[MAX][MAX];

    // Leitura do mapa
    for (int i = 0; i < rows; ++i) {
        scanf("%s", map[i]);
    }

    Pair visited[MAX * MAX]; // Array para armazenar as posições visitadas
    int visitedCount = 0;

    bool foundTreasure = false;
    Pair pos = {0, 0}; // Posição inicial

    while (true) {
        char currChar = map[pos.x][pos.y];
        visited[visitedCount++] = pos;

        if (currChar == '*') {
            foundTreasure = true;
            break;
        }

        if (currChar == '.') {
            break;
        }

        if (currChar == '<') {
            if (pos.y - 1 < 0) {
                break;
            }

            for (int i = pos.y - 1; i >= 0; --i) {
                pos.y = i;
                if (map[pos.x][pos.y] != '.') {
                    break;
                }
            }
        } else if (currChar == '>') {
            if (pos.y + 1 >= columns) {
                break;
            }

            for (int i = pos.y + 1; i < columns; ++i) {
                pos.y = i;
                if (map[pos.x][pos.y] != '.') {
                    break;
                }
            }
        } else if (currChar == '^') {
            if (pos.x - 1 < 0) {
                break;
            }

            for (int i = pos.x - 1; i >= 0; --i) {
                pos.x = i;
                if (map[pos.x][pos.y] != '.') {
                    break;
                }
            }
        } else {
            if (pos.x + 1 >= rows) {
                break;
            }

            for (int i = pos.x + 1; i < rows; ++i) {
                pos.x = i;
                if (map[pos.x][pos.y] != '.') {
                    break;
                }
            }
        }

        // Verifica se a posição já foi visitada
        if (wasVisited(visited, visitedCount, pos)) {
            break;
        }
    }

    // Imprime o resultado
    printf("%c\n", foundTreasure ? '*' : '!');

    return 0;
}