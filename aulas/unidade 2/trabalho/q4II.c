#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum bool_t {false, true} bool;

bool tem_sinal(char equacoes[], char sinal) {
    for (int i=0; i < strlen(equacoes); i++) {
        if (equacoes[i] == sinal) {
            return true;
        }
    }
    return false;
}

// TODO: retorna string com a equação completa com o resultado da operação inserido
// OBS: Apos opera(), deve-se percorrer a (nova) string novamente
float opera (char numeros[2][100], char op, char equacao[100]) {
    if (op == '@') {
        printf("Erro buscando a operaçao\n");
        return 0;
    } else if (op == '*') {
        return (float)atoi(numeros[0]) * atoi(numeros[1]);
    } else if (op == '/') {
        return (float)atoi(numeros[0]) / atoi(numeros[1]);
    } else if (op == '+') {
        return (float)atoi(numeros[0]) + atoi(numeros[1]);
    } else if (op == '-') {
        return (float)atoi(numeros[0]) - atoi(numeros[1]);
    } else {
        printf("Operação não encontrada.\n");
        return 0;
    }
}

int main() {
    int k = 0;
    int n = 4;  // número de equações
    // cria vetor de strings que pode armazenar até 30 equações com 100 caracteres
    char equacoes[30][100] = {"1+2*3",
                         "1-29*3/4", 
                         "1+1/2", 
                         "2/3+3*4"};
    

    while (k < n) {
        char numeros[2][100];
        int na = 0, ia = 0;
        char op;
        float res = 0;
        // verifica por * ou /
        if (tem_sinal(equacoes[k], '*') || tem_sinal(equacoes[k], '/')) {
            // multiplicação ou divisão
            for (int i=0; i < strlen(equacoes[k]); i++) {
                numeros[na][ia] = equacoes[k][i];
                ia++;
                numeros[na][ia] = '\0';
                // printf("%s\n", numeros[na]);
                // printf("%s %c %s :: %c i = %d\n", numeros[0], op, numeros[1], equacoes[k][i], i);

                if (!isdigit(equacoes[k][i]))  {
                    if (equacoes[k][i] == '*' || equacoes[k][i] == '/') {
                        if (na == 1) {
                            // segundo numero
                            // printf("%s %c %s\n", numeros[0], op, numeros[1]);
                            na++;
                            res = opera(numeros, op, equacoes[i]);
                            printf("%.2f\n", res);
                        } else {
                            numeros[na][ia-1] = '\0';
                            // printf("dentro %s\n", numeros[na]);
                            op = equacoes[k][i];   // guarda operação após o primeiro numero
                            na++;
                            ia = 0;
                        }
                    } else {
                        if (na == 1) {
                            // segundo numero
                            // printf("%s %c %s\n", numeros[0], op, numeros[1]);
                            na++;
                            res = opera(numeros, op, equacoes[i]);
                            printf("%.2f\n", res);
                        } else {
                            ia = 0;
                        }
                    }
                } else {
                     if (i == strlen(equacoes[k])-1 && na == 1) {
                        //ultimo digito e segundo numero nao preenchido
                        res = opera(numeros, op, equacoes[i]);
                        na++;
                        printf("%.2f\n", res);
                     }
                }
            }
        }
        k++;
    }

    return 0;
}