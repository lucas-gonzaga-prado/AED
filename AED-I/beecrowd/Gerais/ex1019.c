#include <stdio.h>

int main (){
    int segundos;
    int h = 0, m = 0, s = 0;

    printf("");
    scanf("%d", &segundos);

    s = segundos % 60;
    m = (segundos % 3600) / 60;
    h = segundos / 3600;

    printf("%d:%d:%d\n",h,m,s);

    return 0;
}