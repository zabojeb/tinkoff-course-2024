#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> stack; // тссссс...

    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            int num;
            cin >> num;
            stack.push_back(num);
        }
        else
        {
            int b = stack.back();
            stack.pop_back();

            int a = stack.back();
            stack.pop_back();

            if (type == 1)
            {
                stack.push_back(a + b);
            }
            else if (type == 2)
            {
                stack.push_back(a - b);
            }
            else
            {
                stack.push_back(a * b);
            }
        }
    }

    cout << stack.back() << endl;

    return 0;
}
