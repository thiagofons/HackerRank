#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sum(int n){
    int res = 0, num = n;
    while(num > 0){
        res += num%10;
        num = num/10;
    }
    return res;
}

int main() {
	
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    
    return 0;
}