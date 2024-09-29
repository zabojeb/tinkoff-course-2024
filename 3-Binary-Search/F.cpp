#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, k;
    cin >> a >> b >> k;

    vector<long long> xs;
    for (long long x = 1; x * x <= b; ++x)
    {
        long long x2 = x * x;
        if (x2 >= a)
        {
            xs.push_back(x2);
        }
    }

    vector<long long> ys;
    for (long long y = 1; y * y * y <= b; ++y)
    {
        long long y3 = y * y * y;
        if (y3 >= a)
        {
            ys.push_back(y3);
        }
    }

    long long count = 0;
    for (int i = 0; i < xs.size(); ++i)
    {
        long long sq = xs[i];
        auto l = lower_bound(ys.begin(), ys.end(), sq - k);
        auto r = upper_bound(ys.begin(), ys.end(), sq + k);
        count += distance(l, r);
    }

    cout << count << endl;
    return 0;
}
