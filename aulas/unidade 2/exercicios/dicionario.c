#include <stdio.h>
#include <string.h>

typedef struct dicionario_t {
    int n;
    char chaves[100][100];
    char valores[100][100];
} dicionario;

void add_valor(dicionario* dic, char chave[], char val[]) {
    int pos = -1;
    for (int i=0; i<dic->n; i++) {
        if (strcmp(dic->chaves[i], chave) == 0) {
            pos = i;
            printf("%d %s : %s\n", pos, dic->chaves[i], chave);
            break;
        }
    }
    if (pos >= 0) {
        strcpy(dic->valores[pos], val);
    } else {
        strcpy(dic->chaves[dic->n], chave);
        strcpy(dic->valores[dic->n], val);
        dic->n++;
    }

}

void print_dic(dicionario* dic) {
    printf("{");
    for (int i=0; i<dic->n; i++) {
        printf("%s: %s, ", dic->chaves[i], dic->valores[i]);
    }
    printf("\b\b}\n");
}

int main() {
    dicionario dic;
    
    dic.n = 3;
    strcpy(dic.chaves[0], "k1");
    strcpy(dic.chaves[1], "k2");
    strcpy(dic.chaves[2], "k3");
    strcpy(dic.valores[0], "v1");
    strcpy(dic.valores[1], "v2");
    strcpy(dic.valores[2], "v3");

    print_dic(&dic);
    add_valor(&dic, "k2", "val2.2");
    print_dic(&dic);

    return 0;
}