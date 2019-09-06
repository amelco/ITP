#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fix_name(char* str){
    int i = 0;
    str[0] = toupper(str[0]);
    while (str[i]!='\0'){
        if (str[i]==' ') str[i+1] = toupper(str[i+1]);
        i++;
    }
}

int main(){
    char nome1[50];
    char nome2[50];

    scanf("%[^\n]", nome1);
    scanf(" %[^\n]", nome2);

    if(strcmp(nome1, nome2) == 0) printf("Homonimos\n");

    fix_name(nome1);
    printf("%s\n", nome1);

    return 0;
}
