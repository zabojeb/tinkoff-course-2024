#include <deque>
#include <iostream>

using namespace std;

int main() {
  int Q;
  cin >> Q;

  deque<long long> cs;
  deque<long long> xs;
  while (Q--) {
    int q;
    cin >> q;

    if (q == 1) {
      long long x, c;
      cin >> x >> c;

      cs.push_back(c);
      xs.push_back(x);
    } else {
      long long c;
      cin >> c;

      long long sum = 0;

      while (c > 0) {
        if (cs.front() < c) {
          sum += cs.front() * xs.front();

          c -= cs.front();

          cs.pop_front();
          xs.pop_front();
        } else {
          sum += c * xs.front();

          long long new_c = cs.front() - c;
          long long new_x = xs.front();

          cs.pop_front();
          xs.pop_front();
          if (new_c != 0) {
            cs.push_front(new_c);
            xs.push_front(new_x);
          }

          c -= c;
        }
      }

      cout << sum << endl;
    }
  }

  return 0;
}
