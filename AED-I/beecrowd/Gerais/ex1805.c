#include <stdio.h>

int main(){
    unsigned long long int soma1, soma2, total;
    long long int a, b;

    scanf("%lli %lli", &a, &b);

    //Soma dos n primeiros numeros naturais = n(n+1) / 2.
    soma1 = a * (a + 1) / 2;
    soma2 = b * (b + 1) / 2;

    total = soma2 - soma1 + a;

    printf("%llu\n", total);
    return 0;
}