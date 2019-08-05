#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    if (n1 == n2){
        printf("Números iguais\n");
    } else if (n2 < n1) {
        while (n1 >= n2) {
            printf("%d\n", n2);
            n2++;
        }
    } else {
        while (n2 >= n1) {
            printf("%d\n", n1);
            n1++;
        }
    }
}