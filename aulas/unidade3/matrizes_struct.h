/*matrizes_struct.h*/

#ifndef matrizes_struct_h
#define matrizes_struct_h
typedef struct matriz_t

{

    int valores[50][50];

    int n, m;

} matriz;

void matSub_struct(matriz *mr, matriz *m1, matriz *m2);

void matSum_struct(matriz *mr, matriz *m1, matriz *m2);

#endif