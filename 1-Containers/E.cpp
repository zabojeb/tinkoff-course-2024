#include <algorithm>
#include <deque>
#include <iostream>

#define push push_back
#define top back
#define pop pop_back

using namespace std;

int main() {
  int q;
  cin >> q;

  deque<long long> s1, s2, min_s1, min_s2;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      long long x;
      cin >> x;
      s1.push(x);
      if (min_s1.empty()) {
        min_s1.push(x);
      } else {
        min_s1.push(min(min_s1.back(), x));
      }
    } else if (type == 2) {
      if (s2.empty()) {
        while (!s1.empty()) {
          s2.push(s1.back());
          if (min_s2.empty()) {
            min_s2.push(s1.back());
          } else {
            min_s2.push(min(min_s2.back(), s1.back()));
          }
          s1.pop();
          min_s1.pop();
        }
      }
      cout << s2.back() << endl;
      s2.pop();
      min_s2.pop();
    } else if (type == 3) {
      int i;
      cin >> i;

      i--;

      if (i < s2.size()) {
        cout << s2[s2.size() - 1 - i] << endl;
      } else {
        cout << s1[i - s2.size()] << endl;
      }
    } else {
      if (min_s2.empty()) {
        cout << min_s1.back() << endl;
      } else if (min_s1.empty()) {
        cout << min_s2.back() << endl;
      } else {
        cout << min(min_s1.back(), min_s2.back()) << endl;
      }
    }
  }
}
