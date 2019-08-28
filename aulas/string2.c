#include <stdio.h>
#include <string.h>

void str_n_cat(char* dest, char* str, int n){
    for (int i=0; i<n; i++){
        strcat(dest, str);
    }
}

int main(){
    char* s = "Teste";
    char d[50] = "";

    str_n_cat(d, s, 3);
    printf("%s\n", d);
    
    return 0;
}