#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    stack<long long> s1_val, s2_val;
    stack<long long> s1_min, s2_min;

    long long q;
    cin >> q;

    for (long long i = 0; i < q; ++i)
    {
        long long n;
        cin >> n;

        if (n == 1)
        {
            long long x;
            cin >> x;

            s1_val.push(x);

            s1_min.push(s1_min.empty() ? x : min(x, s1_min.top()));
        }
        else if (n == 2)
        {
            if (s2_val.empty())
            {
                while (!s1_val.empty())
                {
                    long long val = s1_val.top();
                    s1_val.pop();
                    s1_min.pop();

                    s2_val.push(val);

                    long long new_min = s2_min.empty() ? val : min(val, s2_min.top());
                    s2_min.push(new_min);
                }
            }

            long long last_element = s2_val.top();
            s2_val.pop();
            s2_min.pop();
            cout << last_element << endl;
        }
        else if (n == 3)
        {
            long long idx;
            cin >> idx;

            vector<long long> temp;

            while (!s2_val.empty())
            {
                temp.push_back(s2_val.top());
                s2_val.pop();
            }

            reverse(temp.begin(), temp.end());

            while (!s1_val.empty())
            {
                temp.push_back(s1_val.top());
                s1_val.pop();
            }

            cout << temp[idx - 1] << endl;

            for (long long j = temp.size() - 1; j >= 0; --j)
            {
                s1_val.push(temp[j]);

                s1_min.push(s1_min.empty() ? temp[j] : min(temp[j], s1_min.top()));
            }
        }
        else if (n == 4)
        {
            long long min_s1, min_s2;

            if (s1_min.empty())
            {
                min_s1 = 10^18;
            }
            else
            {
                min_s1 = s1_min.top();
            }

            if (s2_min.empty())
            {
                min_s2 = 10^18;
            }
            else
            {
                min_s2 = s2_min.top();
            }

            cout << min(min_s1, min_s2) << endl;
        }
    }

    return 0;
}