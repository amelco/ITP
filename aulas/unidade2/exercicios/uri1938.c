#include <stdio.h>

typedef struct ret_t {
    int x1, y1;
    int x2, y2;
} ret;

typedef struct poste_t {
    int x, y;
} poste;

int main() {
    int num_postes;
    poste p[50];

    scanf("%d", &num_postes);

    int i=0;
    while (i < num_postes) {
        scanf("%d %d", &p[i].x, &p[i].y);
        i++;
    }

    // verifica se é possível formar retangulo (2 a 2 pontos)
    i=0;
    while(i < num_postes) {
        if(p[i].x != p[i+1].x && p[i].y != p[i+1].y) {
            // é possível
            // verifica se existe um poste no retangulo formado pelos 2 postes
            
        } else {
            // não é possível
            // muda os postes de referencia
        }
    }

    return 0;
}