#include <stdio.h>
int main()
{
    int i, alternativa;
    char nome[50];
    FILE *arquivo = fopen("respostas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo");
    }
    else
    {
        printf("Digite seu nome: ");
        scanf("%s", nome);
        fprintf(arquivo, "Aluno: %s\n", nome);
        for (i = 0; i < 10; i++)
        {
            printf("Questão %d: ", i + 1);
            scanf("%d", &alternativa);
            fprintf(arquivo, "Resposta %d: %d\n", i + 1, alternativa);
        }
        fclose(arquivo);
    }
    return 0;
}