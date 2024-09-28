#include <iostream>
#include <vector>

const long long inf = 1e9;

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int l = -1;
    int r = inf;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (m / x + m / y >= n - 1)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r + min(x, y);
}