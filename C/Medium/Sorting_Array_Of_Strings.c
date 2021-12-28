#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int qnt_a = strlen(a), qnt_b = strlen(b);
    
    // A
    for(int i = 0; a[i] != '\0'; i++){
        for(int j = i + 1; a[j] != '\0'; j++){
            if(a[i] == a[j])
                qnt_a--;
        }
    }

    // B
    for(int i = 0; b[i] != '\0'; i++){
        for(int j = i + 1; b[j] != '\0'; j++){
            if(b[i] == b[j])
                qnt_b--;
        }
    }

    // Result
    if(qnt_a < qnt_b)
        return -1;
    if(qnt_a > qnt_b)
        return 1;

    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = 0, len_b = 0;

    for(; a[len_a] != '\0'; len_a++);
    for(; b[len_b] != '\0'; len_b++);
    
    // Result
    if(len_a < len_b)
        return -1;
    if(len_a > len_b)
        return 1;

    return lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *aux;
    
    for(int i = 0; i < len; i++){
        int menor = i;

        for(int j = i+1; j < len; j++){
            if(cmp_func(arr[j], arr[menor]) == -1)
                menor = j;
        }

        if(menor != i){
            aux = arr[menor];
            arr[menor] = arr[i];
            arr[i] = aux;
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}