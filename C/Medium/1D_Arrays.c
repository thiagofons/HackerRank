#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, valor, soma = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &valor);
        soma += valor;        
    }

    printf("%d\n", soma);   
    return 0;
}