#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Error tolerance for zero detection ***
// Decreasing ERR will treat more values as non-zero
// Increasing ERR will treat more values as zero
#define ERR 0.0001

// *** MODIFIABLE: Maximum system size ***
#define MAX_SIZE 20

// Prints the augmented matrix in a readable format
void printMatrix(float a[][MAX_SIZE + 1], int n) {
    printf("\nCurrent matrix state:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("| %.4f\t", a[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// Swaps two rows in the matrix
void swapRows(float a[][MAX_SIZE + 1], int i, int j, int n) {
    for (int k = 0; k < n + 1; k++) {
        float temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
}

// Checks if the system has a unique solution
// Returns 0 if any diagonal element is too close to zero
_Bool checkSolvability(float a[][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) <= ERR) {
            return 0;
        }
    }
    return 1;
}

// Performs forward elimination to convert matrix to upper triangular form
void forwardElimination(float a[][MAX_SIZE + 1], int n) {
    float ratio;
    
    for (int i = 0; i < n; i++) {
        // If the pivot element is too small, swap rows
        if (fabs(a[i][i]) < ERR) {
            int swapped = 0;
            for (int k = i + 1; k < n; k++) {
                if (fabs(a[k][i]) > ERR) {
                    swapRows(a, i, k, n);
                    swapped = 1;
                    break;
                }
            }
            if (!swapped) {
                printf("Matrix is singular or has infinitely many solutions.\n");
                return;
            }
        }

        for (int j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
        printf("After eliminating variable x%d:\n", i + 1);
        printMatrix(a, n);
    }
}

// Performs back substitution to find solution vector
void backSubstitution(float a[][MAX_SIZE + 1], float x[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

// Main function to solve the system using Gaussian elimination
void gaussianElimination(float a[][MAX_SIZE + 1], int n) {
    float x[MAX_SIZE];
    
    printf("\nInitial augmented matrix:\n");
    printMatrix(a, n);
    
    forwardElimination(a, n);
    
    if (!checkSolvability(a, n)) {
        return;
    }
    
    backSubstitution(a, x, n);
    
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float a[MAX_SIZE][MAX_SIZE + 1];
    
    // User input for number of equations
    do {
        printf("Enter the number of equations (1-%d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n < 1 || n > MAX_SIZE) {
            printf("Invalid size. Please try again.\n");
        }
    } while (n < 1 || n > MAX_SIZE);
    
    // User input for augmented matrix
    printf("\nEnter the elements of augmented matrix:\n");
    printf("Format: [coefficients] [constant]\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d: ", i + 1);
        for (int j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    
    // Call Gaussian Elimination
    gaussianElimination(a, n);
    
    return 0;
}
