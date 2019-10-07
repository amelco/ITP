#include <stdio.h>
#include <string.h>

void freq(char frase[1000], char diferentes[100][100]) {

}

int main() {
    char texto[1000] = "morbi justo mauris, ornare a elementum nec, ultricies eget justo.";
    char palavra[100] = "";
    char unicas[100][100];
    int iu = 0, ip=0;
    int cont = 0;

    for (int i=0; i<strlen(texto); i++) {
        if (texto[i] == ',' || texto[i] == '.') continue;
        if (texto[i] != ' ') {
            palavra[ip] = texto[i];
            palavra[ip+1] = '\0';
            ip++;
        } else {
            // printf("%d %s\n", i, palavra);

            if (iu == 0) { 
                strcpy(unicas[iu], palavra);
                iu++;
            }
            for (int j=0; j<iu; j++) {
                if (strcmp(palavra, unicas[j]) == 0) cont++;
            }
            if (cont == 0) {
                strcpy(unicas[iu], palavra);
                iu++;
            }
            strcpy(palavra, "");
            ip=0;
        }
        cont = 0;
    }

    printf("Diferentes: {");
    for (int i=0; i<iu; i++) {
        printf("\"%s\", ", unicas[i]);
    }
    printf("\b\b}\n");

    return 0;
}