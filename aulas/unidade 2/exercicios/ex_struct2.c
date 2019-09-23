#include <stdio.h>

typedef struct vetor_t {
    int len;
    int value[200];
} vetor;

void soma_vec(vetor* v1, vetor* v2, vetor* res) {
    res->len = v1->len;
    for (int i=0; i<v1->len; i++) {
        res->value[i] = v1->value[i] + v2->value[i];
    }
}

void concat_vec(vetor* v1, vetor* v2, vetor* res) {
    int i = 0;
    res->len = v1->len + v2->len;
    while (i < res->len) {
        if (i < v1->len) res->value[i] = v1->value[i];
        else res->value[i] = v2->value[i-v1->len];
        i++;
    }
}

int main() {
    vetor v1;
    vetor v2;
    vetor res;

    v1.len = 5;
    v2.len = v1.len;
    for (int i=0; i < v1.len; i++) {
        v1.value[i] = i+1;
        v2.value[i] = 5-i;
    }

    soma_vec(&v1, &v2, &res);

    for (int i=0; i < res.len; i++) {
        printf("%d ", res.value[i]);
    }
    printf("\n");

    concat_vec(&v1, &v2, &res);

    for (int i=0; i < res.len; i++) {
        printf("%d ", res.value[i]);
    }
    printf("\n");

    return 0;
}