#include <stdio.h>
#include <math.h>
#include <conio.h>

#define err 0.001

int main()
{

    // 2 -1 0 -1 2 -1 0 -1 2
    //  1 0 0
    float lmd_old = 0;
    float lmd_new = 0;
    float temp;
    int n, i, j;
    float A[20][20], Y[20], X[20];

    printf("Order of matrix ::");
    scanf("%d", &n);

    // matrix element
    printf("Enter elements ::");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // printf("%d%d :: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // eigen vector
    printf("Enter vector ::");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &X[i]);
    }

    do
    {
        // y = ax
        // evaluate lmd_new
        for (i = 1; i <= n; i++)
        {
            Y[i] = 0;
            for (j = 1; j <= n; j++)
            {
                Y[i] += A[i][j] * X[j];
                if (fabs(Y[i]) > lmd_new)
                {
                    lmd_new = fabs(Y[i]);
                }
            }
        }

        // x =1/lmd_new (Y)
        for (i = 1; i <= n; i++)
        {
            X[i] = (1 / lmd_new) * Y[i];
        }

        temp = fabs(lmd_old - lmd_new);
        if (temp > err)
        {
            lmd_old = lmd_new;
        }

    } while (temp > err);

    // output
    printf("Eigen value :: %f \n", lmd_new);
    printf("Eigen vector:: [");
    for (int i = 1; i <= n; i++)
    {
        printf("%f\t", X[i]);
    }
    printf("]");
    getch();
    return 0;
}