#include <stdio.h>

int main()
{
    FILE *a;
    char str[100];

    a = fopen("a.txt", "w+");

    fputs("escrevi", a);

    fseek(a, 0, SEEK_SET);

    fputs("escrevi denovo", a);

    fseek(a, 7, SEEK_SET);

    fgets(str, 100, a); //lê " denovo    "

    printf("%s\n ",
           str);
    fputs(" denovo denovo", a);

    fseek(a, 0, SEEK_SET);

    fgets(str, 100, a); //lê escrevi denovo denovo denovo

    printf("%s\n ", str);

    fclose(a);
    return (0);
}