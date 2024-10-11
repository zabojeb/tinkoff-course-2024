#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  long long q;
  cin >> q;

  vector<vector<long long>> board(n + 1, vector<long long>(m + 1, 0));

  while (q--) {
    long long lx, ly, rx, ry, x;
    cin >> lx >> ly >> rx >> ry >> x;

    --lx;
    --ly;
    --rx;
    --ry;

    board[lx][ly] += x;

    if (rx + 1 < n)
      board[rx + 1][ly] -= x;

    if (ry + 1 < m)
      board[lx][ry + 1] -= x;

    if (rx + 1 < n and ry + 1 < m)
      board[rx + 1][ry + 1] += x;
  }

  vector<vector<long long>> answer(n, vector<long long>(m, 0));

  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (i > 0)
        board[i][j] += board[i - 1][j];
      if (j > 0)
        board[i][j] += board[i][j - 1];
      if (i > 0 and j > 0)
        board[i][j] -= board[i - 1][j - 1];

      answer[i][j] = board[i][j];
    }
  }

  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cout << answer[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}