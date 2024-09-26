#include <iostream>
#include <stack>

using namespace std;

stack<int> s1, s2;
stack<int> min_s1, min_s2;

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int req;
        cin >> req;

        if (req == 1)
        {
            int x;
            cin >> x;

            s1.push(x);

            if (min_s1.empty())
            {
                min_s1.push(x);
            }
            else
            {
                min_s1.push(min(x, min_s1.top()));
            }
        }
        else if (req == 2)
        {
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    int x = s1.top();
                    s1.pop();
                    s2.push(x);
                    if (min_s2.empty())
                    {
                        min_s2.push(x);
                    }
                    else
                    {
                        min_s2.push(min(x, min_s2.top()));
                    }
                    min_s1.pop();
                }
            }

            int x = s2.top();
            s2.pop();
            min_s2.pop();

            cout << x << endl;
        }
        else if (req == 3)
        {
            int index;
            cin >> index;
            index--;

            if (s2.empty())
            {
                while (!s1.empty())
                {
                    int x = s1.top();
                    s1.pop();
                    s2.push(x);
                    if (min_s2.empty())
                    {
                        min_s2.push(x);
                    }
                    else
                    {
                        min_s2.push(min(x, min_s2.top()));
                    }
                    min_s1.pop();
                }
            }

            stack<int> temp;
            for (int j = 0; j < index; j++)
            {
                temp.push(s2.top());
                s2.pop();
            }

            cout << s2.top() << endl;

            while (!temp.empty())
            {
                s2.push(temp.top());
                temp.pop();
            }
        }
        else if (req == 4)
        {
            if (s1.empty())
            {
                cout << min_s2.top() << endl;
            }
            else if (s2.empty())
            {
                cout << min_s1.top() << endl;
            }
            else
            {
                cout << min(min_s1.top(), min_s2.top()) << endl;
            }
        }
    }

    return 0;
}