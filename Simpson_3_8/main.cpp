#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Function to integrate ***
// Replace this function definition to compute different integrals
float F(float x)
{
    return 1 / (1 + x * x);
}

// Implements Simpson's 3/8 Rule for numerical integration
// Parameters:
//   a: Lower limit of integration
//   b: Upper limit of integration
//   n: Number of segments (must be a multiple of 3)
// Returns: Approximated integral value
float simpsonsThreeEighthsRule(float a, float b, int n)
{
    float h = (b - a) / n;
    float sum1 = 0, sum2 = 0, x;

    printf("x\t\tF(x)\n");
    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;
        printf("%.5f\t\t%.5f\n", x, F(x));
        if (i % 3 != 0)
        {
            sum1 += 3 * F(x);
        }
        else
        {
            sum2 += 2 * F(x);
        }
    }
    float I = (3 * h / 8) * (F(a) + sum1 + sum2 + F(b));
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
        printf("Number of segments (multiple of 3) :: ");
        scanf("%d", &n);
        if (n % 3 != 0)
        {
            printf("Number of segments must be a multiple of 3. Please try again.\n");
        }
    } while (n % 3 != 0);

    simpsonsThreeEighthsRule(a, b, n);
    return 0;
}