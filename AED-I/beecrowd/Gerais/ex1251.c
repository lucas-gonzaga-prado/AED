#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1005

typedef struct {
    int freq;
    char ch;
} Pair;

int comp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    if (p1->freq == p2->freq) return p2->ch - p1->ch;
    return p1->freq - p2->freq;
}

int main() {
    char str[MAX_LEN];
    int first = 1;
    
    while (fgets(str, MAX_LEN, stdin)) {
        int frequency[256] = {0};
        Pair sorted[256];
        int count = 0;
        
        for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            frequency[(unsigned char)str[i]]++;
        }
        
        for (int i = 0; i < 256; i++) {
            if (frequency[i] > 0) {
                sorted[count].ch = (char)i;
                sorted[count].freq = frequency[i];
                count++;
            }
        }
        
        qsort(sorted, count, sizeof(Pair), comp);
        
        if (!first) printf("\n");
        first = 0;
        
        for (int i = 0; i < count; i++) {
            printf("%d %d\n", sorted[i].ch, sorted[i].freq);
        }
    }
    
    return 0;
}