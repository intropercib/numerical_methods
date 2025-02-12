#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Error tolerance for convergence ***
// Decreasing ERR (e.g., 0.00001) will give more accurate results but need more iterations
// Increasing ERR (e.g., 0.001) will give less accurate results but converge faster
#define ERR 0.001

// Function to perform power method for dominant eigenvalue
// Parameters:
//   n: Order of the matrix
//   A: Coefficient matrix
//   X: Initial eigenvector (modifiable for different inputs)
void powerMethod(int n, float A[20][20], float X[20])
{
    float Y[20], lambda_old = 0, lambda_new = 0, temp;
    printf("Iteration	 Eigenvalue	 Eigenvector\n");
    int iteration = 0;

    do
    {
        lambda_new = 0;
        // Compute Y = A * X
        for (int i = 0; i < n; i++)
        {
            Y[i] = 0;
            for (int j = 0; j < n; j++)
            {
                Y[i] += A[i][j] * X[j];
            }
            if (fabs(Y[i]) > lambda_new)
            {
                lambda_new = fabs(Y[i]);
            }
        }

        // Normalize X
        for (int i = 0; i < n; i++)
        {
            X[i] = Y[i] / lambda_new;
        }

        temp = fabs(lambda_old - lambda_new);
        lambda_old = lambda_new;

        // Print iteration details
        printf("%d\t\t %.5f\t [", ++iteration, lambda_new);
        for (int i = 0; i < n; i++)
        {
            printf("%.5f ", X[i]);
        }
        printf("]\n");

    } while (temp > ERR);

    // Output final results
    printf("\nDominant Eigenvalue :: %.5f\n", lambda_new);
    printf("Corresponding Eigenvector :: [");
    for (int i = 0; i < n; i++)
    {
        printf("%.5f\t", X[i]);
    }
    printf("]\n");
}

int main()
{
    // *** MODIFIABLE: Order of the matrix ***
    // Change value to test different matrix sizes
    int n = 3;

    // *** MODIFIABLE: Matrix A ***
    // Replace values to compute eigenvalues for different matrices
    float A[20][20] = {{2, -1, 0},
                       {-1, 2, -1},
                       {0, -1, 2}};

    // *** MODIFIABLE: Initial eigenvector ***
    // Change values to test different starting vectors
    float X[20] = {1, 0, 0};

    powerMethod(n, A, X);
    return 0;
}