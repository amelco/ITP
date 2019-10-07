#include <stdio.h>
#include <string.h>

typedef struct pessoa_t {
    char nome[50];
    char sexo;
    int idade;
} pessoa;

void preenche_pessoa (char nome[], char sexo, int idade, pessoa* p) {
    strcpy(p->nome, nome);
    p->sexo = sexo;
    p->idade = idade;

}

int main() {
    pessoa aluno;

    preenche_pessoa("Andre", 'M', 37, &aluno);
    printf("Nome: %7s\nGênero: %c\nIdade: %3d\n", aluno.nome, aluno.sexo, aluno.idade);
    
    return 0;
}