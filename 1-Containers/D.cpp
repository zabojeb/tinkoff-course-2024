#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int q;
    cin >> q;

    vector<long> stack;
    vector<long> min_stack;

    while (q--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            long x;
            cin >> x;

            stack.push_back(x);

            if (min_stack.size() == 0 or x < min_stack.back())
            {
                min_stack.push_back(x);
            }
            else
            {
                min_stack.push_back(min_stack.back());
            }
        }
        else if (n == 2)
        {
            cout << stack.back() << endl;
            stack.pop_back();
            min_stack.pop_back();
        }
        else if (n == 3)
        {
            cout << min_stack.back() << endl;
        }
    }

    return 0;
}
