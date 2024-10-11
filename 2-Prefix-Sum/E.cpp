#include <iostream>
#include <vector>

using namespace std;

long long calc(long long x, long long y, long long z, const vector<vector<vector<long long>>> &sums) {
  if (x < 0 or y < 0 or z < 0)
    return 0;
  return sums[x][y][z];
}

int main() {
  long long xs, ys, zs;
  cin >> xs >> ys >> zs;

  vector<vector<vector<long long>>> a(xs, vector<vector<long long>>(ys, vector<long long>(zs)));
  for (long long x = 0; x < xs; x++)
    for (long long y = 0; y < ys; y++)
      for (long long z = 0; z < zs; z++)
        cin >> a[x][y][z];

  vector<vector<vector<long long>>> sums(xs,
                                   vector<vector<long long>>(ys, vector<long long>(zs, 0)));

  for (long long x = 0; x < xs; x++)
    for (long long y = 0; y < ys; y++)
      for (long long z = 0; z < zs; z++) {
        sums[x][y][z] =
            a[x][y][z] + calc(x - 1, y, z, sums) + calc(x, y - 1, z, sums) +
            calc(x, y, z - 1, sums) - calc(x - 1, y - 1, z, sums) -
            calc(x - 1, y, z - 1, sums) - calc(x, y - 1, z - 1, sums) +
            calc(x - 1, y - 1, z - 1, sums);
      }

  long long Q;
  cin >> Q;

  while (Q--) {
    long long x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    x1--;
    y1--;
    z1--;
    x2--;
    y2--;
    z2--;

    long long answer =
        calc(x2, y2, z2, sums) - calc(x1 - 1, y2, z2, sums) -
        calc(x2, y1 - 1, z2, sums) - calc(x2, y2, z1 - 1, sums) +
        calc(x1 - 1, y1 - 1, z2, sums) + calc(x1 - 1, y2, z1 - 1, sums) +
        calc(x2, y1 - 1, z1 - 1, sums) - calc(x1 - 1, y1 - 1, z1 - 1, sums);

    cout << answer << " ";
  }

  cout << endl;

  return 0;
}
