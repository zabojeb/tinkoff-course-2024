#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;

    cin >> s;

    int counter = 0;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            counter++;
        }
        else if (counter > 0)
        {
            counter--;
        }
        else
        {
            cout << "no";
            return 0;
        }
    }

    if (counter > 0)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }

    return 0;
}
