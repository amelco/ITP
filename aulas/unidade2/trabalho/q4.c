#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// float resolve (char equacao[], int* ini);
float resolve (char equacao[]);
float opera (char numeros[2][100], char op);

// retorna o resultado dos 2 numeros proximos à operação
float resolve (char equacao[]) {
    char numeros[2][100];
    char new_eq[100];
    int na = 0;     // posicao do numero auxiliar (0 ou 1)
    int ia = 0;     // indice do caractere do numero auxiliar na
    char op = '@';  // operador. Inicializa com @ para tratamento de erro

    int c_m = 0;        // contador de multiplicação/divisao
    
    // verifica se há multiplicação ou divisão
    for (int i=0; i < strlen(equacao); i++) {
        if (equacao[i] == '*' || equacao[i] == '/') {
            c_m++;
        }
    }

    if (c_m > 0){
        // há mutiplicação ou divisão
        for (int i=0; i < strlen(equacao); i++) {
            numeros[na][ia] = equacao[i];
            numeros[na][ia+1] = '\0';
            // printf("%s %c %s :: %c\n", numeros[0], op, numeros[1], equacao[i]);

            if (equacao[i] == '+' || equacao[i] == '-' || i == strlen(equacao)-1) {
                // printf("mais ou fim\n");
                if (na == 0) {
                    // primeiro numero
                    ia = 0;
                    continue;
                } else {
                    // segundo número
                    numeros[na][ia] = '\0';

                }
            }
            if (equacao[i] == '*' || equacao[i] == '/') {
                numeros[na][ia] = '\0';
                op = equacao[i];   // guarda operação após o primeiro numero
                na++;
                ia = -1;
            }
            ia++;
        }
        printf("Fim de varredura da eq: %s %c %s = ?", numeros[0], op, numeros[1]);
    }
    else {
        // não há multiplicação ou divisão
        
    }
}

float opera (char numeros[2][100], char op) {
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
    int n = 4;  // número de equações
    // cria vetor de strings que pode armazenar até 30 equações com 100 caracteres
    char equacoes[30][100] = {"123+2*3",
                         "1-2*3/4", 
                         "1+1/2", 
                         "2/3+3*4"};
    int pos = 0;    // posição atual do apontador
    
    int i = 0;
    while (i < n) {
        float res = 0;
        printf("Equação: %s\n", equacoes[i]);
        res = resolve(equacoes[i]);
        printf("resposta = %.2f, pos = %i\n", res, pos);
        i++;
    }

    return 0;
}