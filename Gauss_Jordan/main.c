#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Error tolerance for zero detection ***
// Decrease for higher precision, increase for better handling of near-zero values
#define ERR 0.0001

// *** MODIFIABLE: Maximum system size ***
#define MAX_SIZE 20

// Function to validate the size of the system
_Bool validateSize(int n) {
    return (n > 0 && n <= MAX_SIZE);
}

// Function to print the current state of the augmented matrix
void displayMatrix(float a[][MAX_SIZE + 1], int n) {
    printf("\nCurrent matrix state:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.4f\t\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get input for the augmented matrix
void getInput(float a[][MAX_SIZE + 1], int n) {
    printf("\nEnter the coefficients and constants for each equation:\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d (Enter %d coefficients followed by constant): ", i + 1, n);
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
}

// Function to solve the system using elimination method
void solveSystem(float a[][MAX_SIZE + 1], float x[], int n) {
    float ratio;
    
    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Check for zero pivot
        if (fabs(a[i][i]) < ERR) {
            printf("Error: Zero or near-zero pivot encountered. System may be unsolvable.\n");
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
        printf("After elimination step %d:\n", i + 1);
        displayMatrix(a, n);
    }
    
    // Back substitution
    for (int i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
    }
}

// Function to display the solution
void displaySolution(float x[], int n) {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\t\t\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float a[MAX_SIZE][MAX_SIZE + 1];
    float x[MAX_SIZE];
    
    // Get and validate system size
    do {
        printf("Enter the number of equations (1-%d): ", MAX_SIZE);
        scanf("%d", &n);
        if (!validateSize(n)) {
            printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        }
    } while (!validateSize(n));
    
    // Get system coefficients and constants
    getInput(a, n);
    
    // Display initial matrix
    printf("\nInitial augmented matrix:");
    displayMatrix(a, n);
    
    // Solve the system
    solveSystem(a, x, n);
    
    // Display solution
    displaySolution(x, n);
    
    return 0;
}