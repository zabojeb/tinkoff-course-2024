#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;

    cin >> n;
    cin >> q;

    vector<long long> arr(n + 1, 0);

    for (int i = 0; i < q; i++)
    {
        int l, r, d;
        cin >> l;
        cin >> r;
        cin >> d;

        l--;
        r--;

        arr[l] += d;
        arr[r + 1] -= d;
    }

    vector<long long> result;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << arr[i] << " ";
            result.push_back(arr[i]);
        }
        else
        {
            cout << result[i - 1] + arr[i] << " ";
            result.push_back(result[i - 1] + arr[i]);
        }
    }

    return 0;
}
