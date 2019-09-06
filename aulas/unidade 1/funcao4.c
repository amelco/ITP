#include <stdio.h>

char* func(){
    char* s = "test";
    return s;
}

int main(){
    printf("%s\n", func());
    return 0;
}