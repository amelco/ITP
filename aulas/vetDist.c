#include <stdio.h>
#include <math.h>

double distancia(int p1[], int tam_p1, int p2[], int tam_p2){
    double dist = 0;
    for (int i=0; i<tam_p1; i++)
        dist += pow(p2[i] - p1[i], 2);
    return sqrt(dist);
}

int main(){
    int p1[] = {2,1,3};
    int tam_p1 = 3;
    int p2[] = {1,2,-3};
    int tam_p2 = 3;

    printf("distancia %lf\n", distancia(p1, tam_p1, p2, tam_p2));

    return 0;
}