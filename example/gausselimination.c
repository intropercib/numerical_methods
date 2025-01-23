#include <stdio.h>

int main() {
    int n;
    float a[10][11], x[10], ratio;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the elements of the augmented matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward elimination to convert to upper triangular form
    for (int j = 0; j < n - 1; j++) {  // Column loop
        for (int i = j + 1; i < n; i++) {  // Row loop below the pivot
            ratio = a[i][j] / a[j][j];
            for (int k = 0; k < n + 1; k++) {  // Update the row
                a[i][k] = a[i][k] - ratio * a[j][k];
            }
        }
    }

    // Back substitution to find the solution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];  // Start with the constant term
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];  // Subtract known terms
        }
        x[i] = x[i] / a[i][i];  // Divide by the pivot element
    }

    // Print the solution
    printf("The solution is: \n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
