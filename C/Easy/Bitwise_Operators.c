#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int initial = 1, final = n, and = 0, or = 0, xor = 0, test;

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            test = i & j;
            if(test > and && test < k)
                and = test;
            
            test = i | j;
            if(test > or && test < k)
                or = test;

            test = i ^ j;
            if(test > xor && test < k)
                xor = test;
        }
    }
    printf("%d\n%d\n%d\n", and, or, xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
