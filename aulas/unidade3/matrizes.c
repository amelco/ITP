/*matrizes.c*/

#include "matrizes.h"

void matSub(int n, int m, int mr[n][m], int m1[n][m], int m2[n][m])
{
    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)

        {

            mr[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void matSum(int n, int m, int mr[n][m], int m1[n][m], int m2[n][m])

{

    for (int i = 0; i < n; ++i)

    {

        for (int j = 0; j < m; ++j)

        {

            mr[i][j] = m1[i][j] + m2[i][j];
        }
    }
}