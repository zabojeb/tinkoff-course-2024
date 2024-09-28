#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long h[100], m[100], evil[100];
    long long leave_h[100], leave_m[100];

    for (long long i = 0; i < n; ++i)
    {
        cin >> h[i] >> m[i] >> evil[i];
    }

    queue<pair<long long, long long>> mq;
    long long curr_h = 0, curr_m = 0;

    for (long long i = 0; i < n; ++i)
    {
        while (!mq.empty() &&
               (mq.front().first < h[i] ||
                (mq.front().first == h[i] && mq.front().second <= m[i])))
        {
            mq.pop();
        }

        if ((long long)mq.size() > evil[i])
        {
            leave_h[i] = h[i];
            leave_m[i] = m[i];
        }
        else
        {
            if (mq.empty())
            {
                curr_h = h[i];
                curr_m = m[i];
            }

            curr_m += 20;
            if (curr_m >= 60)
            {
                curr_m -= 60;
                curr_h += 1;
            }

            leave_h[i] = curr_h;
            leave_m[i] = curr_m;

            mq.push({curr_h, curr_m});
        }
    }

    for (long long i = 0; i < n; ++i)
    {
        cout << leave_h[i] << " " << leave_m[i] << endl;
    }

    return 0;
}