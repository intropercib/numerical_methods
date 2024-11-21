#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Error tolerance for the root ***
// Decreasing ERR (e.g., 0.00001) will give more accurate results but need more iterations
// Increasing ERR (e.g., 0.001) will give less accurate results but converge faster
#define ERR 0.0001

// *** MODIFIABLE: Function whose root we want to find ***
// Replace the function body to solve different equations
float F(float x)
{
    return log10(x) - cos(x);
}

// Checks if initial points bracket a root by checking if F(x1) and F(x2) have opposite signs
// Returns true if a root exists between x1 and x2
_Bool checkBracketingCond(float x_1, float x_2)
{
    return ((F(x_1) * F(x_2)) < 0);
}

// Checks if the method has converged to a root based on two conditions:
// 1. Distance between brackets is less than ERR, or
// 2. Function value at midpoint is less than ERR
_Bool checkRoot(float x_m, float x_1, float x_2)
{
    return ((fabs(x_2 - x_1) <= ERR) || (fabs(F(x_m)) <= ERR));
}

// Implements the bisection method algorithm
// Parameters:
//   x_1: Left bracket
//   x_2: Right bracket
// Returns: Approximated root value
float bisectionMethod(float x_1, float x_2)
{
    float x_m;
    printf("x_1\t\t x_2\t\t F(x_1)\t\t F(x_2)\t\t x_m\t\t F(x_m)\n");
    do
    {
        x_m = x_1 + (x_2 - x_1) / 2;
        printf("| %.5f\t| %.5f\t| %.5f\t| %.5f\t| %.5f\t| %.5f\t|\n", x_1, x_2, F(x_1), F(x_2), x_m, F(x_m));

        if (checkBracketingCond(x_1, x_m))
        {
            x_2 = x_m; // Root is in left half
        }
        else
        {
            x_1 = x_m; // Root is in right half
        }
    } while (!checkRoot(x_m, x_1, x_2));
    printf("Root :: %.5f\n", x_m);
    return x_m;
}

int main()
{
    float x_1, x_2;
    // User input
    do
    {
        printf("x_1 :: ");
        scanf("%f", &x_1);
        printf("x_2 :: ");
        scanf("%f", &x_2);
        if (!checkBracketingCond(x_1, x_2))
        {
            printf("Initial guesses do not bracket a root. Please try again.\n");
        }
    } while (!checkBracketingCond(x_1, x_2));
    bisectionMethod(x_1, x_2);
    return 0;
}
