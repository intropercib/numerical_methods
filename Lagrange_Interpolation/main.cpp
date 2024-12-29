#include <iostream>
#include <vector>
using namespace std;

// *** IMPLEMENTS: Lagrange Interpolation Function ***
float lagrange_interpolation(const vector<float> &x, const vector<float> &y, int n, float x0)
{
    float result = 0;

    // *** CALCULATE: Lagrange polynomial sum ***
    for (int i = 0; i <= n; i++)
    {
        float term = y[i]; // Start with the corresponding y-value

        // *** CALCULATE: Lagrange basis polynomials ***
        for (int j = 0; j <= n; j++)
        {
            // Skip the case when i == j to avoid division by zero
            if (i != j)
            {
                term *= (x0 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    // *** MODIFIABLE: Input Data ***
    // Modify the vectors x and y with your data points for interpolation
    vector<float> x = {1, 2, 3, 4, 5};
    vector<float> y = {1, 4, 9, 16, 25};
    int degree = 4;                 // Use n-1 degree polynomial for better results
    float interpolatingValue = 3.1; // The x-value where you want to interpolate

    float result = lagrange_interpolation(x, y, degree, interpolatingValue);

    cout << "x :: " << interpolatingValue << " y :: " << result << " degree of poly :: " << degree << endl;

    return 0;
}
