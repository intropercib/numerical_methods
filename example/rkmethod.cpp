#include <iostream>
#define f(x, y) ((2 * y) / x)

using namespace std;

int main()
{
    float x0, y0, xp, m1, m2, m3, m4, m, y1, x1, h;
    cout << "Enter for x0 y0:: ";
    cin >> x0 >> y0;

    cout << "Enter for h:: ";
    cin >> h;

    cout << "Enter value for xp :: ";
    cin >> xp;

    float n = (xp - x0) / h;

    for (int i = 1; i <= n; i++)
    {
        m1 = f(x0, y0);
        m2 = f((x0 + h / 2), (y0 + m1 * (h / 2)));
        m3 = f((x0 + h / 2), (y0 + m2 * (h / 2)));
        m4 = f((x0 + h), (y0 + m3 * h));
        m = (m1 + 2 * m2 + 2 * m3 + m4) / 6;
        y0 += m * h;
        x0 += h;
    }
    cout << "Result :: " << y0 << endl;

    return 0;
}