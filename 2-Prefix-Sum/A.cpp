#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> sums;
    for (long long i = 0; i < n; i++)
    {
        long long el;
        cin >> el;

        if (sums.empty())
        {
            sums.push_back(el);
        }
        else
        {
            sums.push_back(sums.back() + el);
        }
    }

    long long q;
    cin >> q;

    for (long long i = 0; i < q; i++)
    {
        long long l;
        long long r;

        cin >> l >> r;

        l--;
        r--;

        if (l < 1)
        {
            cout << sums[r] << " ";
        }
        else
        {
            cout << sums[r] - sums[l - 1] << " ";
        }
    }

    return 0;
}