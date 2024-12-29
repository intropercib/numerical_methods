#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, a, b;

    // *** MODIFIABLE: Data for the linear regression ***
    // Modify the values of x and y to fit your dataset for the linear regression
    vector<float> x = {0, 1, 2, 3, 4, 5};    // Example x-values
    vector<float> y = {3, 4, 7, 10, 11, 14}; // Example y-values

    n = x.size();

    for (int i = 0; i < n; i++)
    {
        sumx += x[i];         // Sum of x-values
        sumy += y[i];         // Sum of y-values
        sumxy += x[i] * y[i]; // Sum of x*y
        sumx2 += x[i] * x[i]; // Sum of x^2
    }

    // *** CALCULATE: Coefficients a and b for the linear equation ***
    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx); // Slope (b)
    a = (sumy - b * sumx) / n;                                 // Intercept (a)

    cout << "The equation of the line is y = " << a << " + " << b << "x" << endl;

    return 0;
}
