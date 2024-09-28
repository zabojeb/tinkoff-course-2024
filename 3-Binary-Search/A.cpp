#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        int l = 0;
        int r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (arr[m] > x)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }

        if (arr[l] == x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}