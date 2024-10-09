#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long max_sum = -1e9 - 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;

    sum = max(x, sum + x);
    max_sum = max(max_sum, sum);
  }

  cout << max_sum;

  return 0;
}
