#include <stdio.h>

void _conj(int v1[], int tv1, int set_ret[]) {
    int i, j;
    int tam_atual = 1;
    int tem=0;
    
    // seta elementos de vetor resposta (vr) iguais a -1
    for(int i=0; i<tv1; i++) {
        set_ret[i] = -1;
    }
    
    // iguala o primeiro elemento nao negativo de v1 ao primeiro elemento de vr
    for (int i=0; i<tv1; i++) {
        if(v1[i] >= 0) {
            set_ret[0] = v1[i];
            break;
        }
    }

    // retira elementos repetidos ou negativos
    for (i = 1; i < tv1; i++) {
        tem=0;
        for (j = 0; j < tam_atual; j++) {
            if (v1[i] == set_ret[j] || v1[i] < 0) tem=1;
        }
        if (tem==0) {
            set_ret[tam_atual] = v1[i];
            tam_atual++;
        }
    }
}

void uniao(int v1[], int v2[], int vr[]) {


}

int main() {
    int vec[] = {-16, -1, -2, 2, 2};
    int res[6];
    _conj(vec, 5, res);
    printf("\n");
    for(int i=0; i<5; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
