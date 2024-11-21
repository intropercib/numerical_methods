#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Function whose root we want to find ***
// Modify this function body to solve different equations
float f(float x)
{
    return x * x * x - 4 * x + 1; // Example function (x^3 - 4x + 1)
}

// *** MODIFIABLE: Derivative of the function f(x) ***
// Modify this function body for different derivatives
float g(float x)
{
    return 3 * x * x - 4; // Derivative of the function (3x^2 - 4)
}

// Checks if the derivative at x0 is not zero to avoid division by zero
// Returns true if the derivative is non-zero at x0
_Bool checkDerivative(float x0)
{
    return g(x0) != 0;
}

// Checks if the method has converged based on the error tolerance
// Returns true if the change in the approximation is less than the error tolerance
_Bool checkConvergence(float temp, float ERR)
{
    return fabs(temp) <= ERR;
}

// Implements the Newton-Raphson method algorithm
// Parameters:
//   x0: Initial guess
//   ERR: Error tolerance
// Returns: Approximated root value
float newtonRaphsonMethod(float x0, float ERR)
{
    float x1, temp;
    printf("x0\t\t f(x0)\t\t g(x0)\t\t x1\t\t f(x1)\n");
    do
    {
        x1 = x0 - f(x0) / g(x0);
        temp = x1 - x0;
        printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",
               x0, f(x0), g(x0), x1, f(x1));

        x0 = x1;
    } while (!checkConvergence(temp, ERR));
    return x0;
}

int main()
{
    float x0, ERR;

    // User input
    {
        printf("Enter the initial guess: ");
        scanf("%f", &x0);
        if (!checkDerivative(x0))
        {
            printf("Derivative at x = %.5f is zero. Please choose another initial guess.\n", x0);
        }
    }
    while (!checkDerivative(x0));
    do
    {
        printf("Enter the error tolerance (e.g., 0.0001): ");
        scanf("%f", &ERR);
        if (ERR <= 0)
        {
            printf("Error tolerance must be positive. Please enter a valid value.\n");
        }
    } while (ERR <= 0);

    float root = newtonRaphsonMethod(x0, ERR);
    printf("The root is %.5f\n", root);

    return 0;
}
