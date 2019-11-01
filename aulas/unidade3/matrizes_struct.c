#include "matrizes_struct.h"

void matSub_struct(matriz *mr, matriz *m1, matriz *m2)

{

    for (int i = 0; i < m1->n; ++i)

    {

        for (int j = 0; j < m1->m; ++j)

        {

            mr->valores[i][j] = m1->valores[i][j] - m2->valores[i][j];
        }
    }
}

void matSum_struct(matriz *mr, matriz *m1, matriz *m2)

{

    for (int i = 0; i < m1->n; ++i)

    {

        for (int j = 0; j < m1->m; ++j)

        {

            mr->valores[i][j] = m1->valores[i][j] + m2->valores[i][j];
        }
    }
}