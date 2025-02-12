#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Function to integrate ***
// Replace this function definition to compute different integrals
float F(float x)
{
    return 1 / (1 + x * x);
}

// Implements Simpson's 1/3 Rule for numerical integration
// Parameters:
//   a: Lower limit of integration
//   b: Upper limit of integration
//   n: Number of segments (must be even)
// Returns: Approximated integral value
float simpsonsRule(float a, float b, int n)
{
    float h = (b - a) / n;
    float sum1 = 0, sum2 = 0, x;

    printf("x\t\tF(x)\n");
    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;
        printf("%.5f\t\t%.5f\n", x, F(x));
        if (i % 2 != 0)
        {
            sum1 += 4 * F(x);
        }
        else
        {
            sum2 += 2 * F(x);
        }
    }
    float I = h / 3 * (F(a) + sum1 + sum2 + F(b));
    printf("Result :: %.5f\n", I);
    return I;
}

int main()
{
    float a, b;
    int n;
    // User input
    do
    {
        printf("Lower limit (a) :: ");
        scanf("%f", &a);
        printf("Upper limit (b) :: ");
        scanf("%f", &b);
        printf("Number of segments (even) :: ");
        scanf("%d", &n);
        if (n % 2 != 0)
        {
            printf("Number of segments must be even. Please try again.\n");
        }
    } while (n % 2 != 0);

    simpsonsRule(a, b, n);
    return 0;
}
