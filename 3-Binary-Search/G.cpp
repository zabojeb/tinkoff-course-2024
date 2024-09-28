// когда-нибудь потом я решу её бин. поиском,
// а пока что спасибо Кардано за формулу, крутой мужик!

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double A = b / a;
    double B = c / a;
    double C = d / a;

    double p = (3 * B - A * A) / 3;
    double q = (2 * A * A * A - 9 * A * B + 27 * C) / 27;

    double D = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3);

    double x;
    if (D >= 0)
    {
        double u1 = cbrt(-q / 2 + sqrt(D));
        double u2 = cbrt(-q / 2 - sqrt(D));
        x = u1 + u2;
    }
    else
    {
        double r = sqrt(-(p / 3));
        double t = acos(-q / (2 * r * r * r));
        x = 2 * r * cos(t / 3);
    }

    x = x - A / 3;

    cout << fixed << setprecision(4) << x << endl;

    return 0;
}
