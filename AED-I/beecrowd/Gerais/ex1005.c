#include <stdio.h>
 
int main() {
    double a, b;
    double media = 0;
    
    printf("");
    scanf("%lf %lf", &a, &b);
    
    media = (a * 3.5 + b * 7.5)/11;
    
    printf("MEDIA = %.5lf\n", media);
 
    return 0;
}