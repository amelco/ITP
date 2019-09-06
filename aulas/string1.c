#include <stdio.h>

int main(){
    char input, a;
    int cont = 0;
    char* string = "Neque porro quisquam est qui dolorem ipsum";

    scanf("%c", &input);
    int i=0;
    a = string[i];
    while (a != '\0'){
        if (a==input) {
            printf("%d ", i);
            cont++;
        }
        i++;
        a = string[i];
    }
    printf("\n%d\n", cont);
    return 0;
}