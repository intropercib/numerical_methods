#include <stdio.h>
#include <math.h>

// *** MODIFIABLE: Function defining the differential equation ***
// Replace this function definition for different differential equations
float F(float x, float y)
{
    return (2 * y) / x;
}

// Implements Runge-Kutta 4th order method for solving ODEs
// Parameters:
//   x0: Initial x value
//   y0: Initial y value
//   xp: Target x value
//   h: Step size
// Returns: Approximated y value at xp
float rungeKutta(float x0, float y0, float xp, float h)
{
    float m1, m2, m3, m4, m;
    printf("x\t\ty\n");
    while (x0 < xp)
    {
        m1 = F(x0, y0);
        m2 = F(x0 + h / 2, y0 + m1 * h / 2);
        m3 = F(x0 + h / 2, y0 + m2 * h / 2);
        m4 = F(x0 + h, y0 + m3 * h);
        m = (m1 + 2 * m2 + 2 * m3 + m4) / 6;
        y0 += m * h;
        x0 += h;
        printf("%.5f\t\t%.5f\n", x0, y0);
    }
    printf("Result :: %.5f\n", y0);
    return y0;
}

int main()
{
    float x0, y0, xp, h;
    // User input
    printf("Enter initial values (x0 y0) :: ");
    scanf("%f %f", &x0, &y0);
    printf("Enter step size (h) :: ");
    scanf("%f", &h);
    printf("Enter target x value (xp) :: ");
    scanf("%f", &xp);

    rungeKutta(x0, y0, xp, h);
    return 0;
}