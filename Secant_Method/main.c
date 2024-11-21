#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Function whose root we want to find ***
// Modify this function body to solve different equations
float f(float x)
{
    return x * x * x - 4 * x + 1; // Example function (x^3 - 4x + 1)
}

_Bool checkConvergence(float x1, float x2, float ERR)
{
    return fabs(x1 - x2) <= ERR;
}

int main()
{
    float x1, x2, x3, ERR;

    // User input
    do
    {
        printf("Enter the initial guess: ");
        scanf("%f", &x1);
        printf("Enter the second guess: ");
        scanf("%f", &x2);
        if (fabs(f(x1)) <= 0 || fabs(f(x2)) <= 0)
        {
            printf("Initial guesses do not provide a valid root, please try again.\n");
        }
    } while (fabs(f(x1)) <= 0 || fabs(f(x2)) <= 0);
    do
    {
        printf("Enter the error tolerance (e.g., 0.0001): ");
        scanf("%f", &ERR);
        if (ERR <= 0)
        {
            printf("Error tolerance must be positive. Please enter a valid value.\n");
        }
    } while (ERR <= 0);

    // *** ITERATIVE: Secant Method ***
    printf("x1\t\t f(x1)\t\t x2\t\t f(x2)\t\t x3\t\t f(x3)\n");
    do
    {

        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

        printf("%.3f\t\t %.3f\t\t %.3f\t\t %.3f\t\t %.3f\t\t %.3f\n",
               x1, f(x1), x2, f(x2), x3, f(x3));

        x1 = x2;
        x2 = x3;

    } while (!checkConvergence(x1, x2, ERR)); // Continue until convergence is met

    printf("The root is %.5f\n", x3);

    return 0;
}
