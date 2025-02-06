#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 10005

int m;

int comp(const void *a, const void *b) {
    int A = *(int *)a, B = *(int *)b;
    int modA = A % m, modB = B % m;
    
    if (A < 0) modA = -1 * (abs(A) % m);
    if (B < 0) modB = -1 * (abs(B) % m);
    
    if (modA != modB) return modA - modB;
    if ((A & 1) && !(B & 1)) return -1;
    if (!(A & 1) && (B & 1)) return 1;
    if ((A & 1) && (B & 1)) return B - A;
    return A - B;
}

int main() {
    while (1) {
        int n;
        scanf("%d %d", &n, &m);
        
        if (n == 0 && m == 0) {
            printf("0 0\n");
            break;
        }
        
        int arr[MAX_N];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        qsort(arr, n, sizeof(int), comp);
        
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
    }
    
    return 0;
}
