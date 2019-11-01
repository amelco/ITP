#include <stdio.h>
int main()
{
    int questao, resposta, acertos, i;
    char nome[50];
    int gabarito[10] = {3, 4, 2, 1, 3, 1, 1, 2, 4, 4};
    FILE *arquivo = fopen("respostas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo");
    }
    else
    {
        acertos = 0;
        fscanf(arquivo, "Aluno: %s\n", nome);
        for (i = 0; i < 10; i++)
        {
            fscanf(arquivo, "Resposta %d: %d\n", &questao, &resposta);
            if (gabarito[questao - 1] == resposta)
                acertos++;
        }
        printf("Nota de %s\n", nome);
        printf("%.2f\n", (float)acertos / 10.0);
        fclose(arquivo);
    }
    return 0;
}