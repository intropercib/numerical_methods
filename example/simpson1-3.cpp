#include <iostream>
#include <math.h>
#define f(x) (1 / (1 + (x) * (x)))

using namespace std;

int main()
{
    float a, b, sum1 = 0, sum2 = 0, x = 0;
    int n;
    cout << "Range a and b ::  ";
    cin >> a >> b;
    cout << "No of segments :: ";
    do
    {
        cin >> n;
    } while (n % 2 != 0);
    float h = (b - a) / n;
    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;
        i % 2 != 0 ? sum1 += 4 * f(x) : sum2 += 2 * f(x);
    }
    float I = h / 3 * (f(a) + sum1 + sum2 + f(b));
    cout << "Result :: " << I;

    return 0;
}