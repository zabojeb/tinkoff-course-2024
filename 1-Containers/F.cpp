#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long long n; // Я НЕНАВИЖУ C++ ЕСЛИ ОНО НЕ РАБОТАЛО ИЗ-ЗА ИНТА ТО Я
    cin >> n;

    stack<pair<long long, long long>> st;
    long long count = 0;

    for (long long i = 0; i < n; i++)
    {
        long long booble; // я изобрел новое слово
        cin >> booble;

        if (!st.empty() && st.top().first == booble)
        {
            st.top().second++;
        }
        else
        {
            st.push({booble, 1});
        }

        if (st.top().second >= 3)
        {
            count += st.top().second;
            st.pop();
        }
    }

    cout << count << endl;

    return 0;
}
