#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fix_name(char* str){
    if (islower(str[0])) touper(str[0])
    for (int i=1; i<strlen(str); i++){

    }
}

int main(){
    char str1[50];
    char str2[50];

    scanf("%[^\n]", str1);
    scanf(" %[^\n]", str2);

    if(strcmp(str1, str2) == 0) printf("Homonimos\n");

    return 0;
}
