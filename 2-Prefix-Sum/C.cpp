#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<vector<long long>> board(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long foo;
      cin >> foo;

      long long ie, je, ije;
      if (i == 0) {
        ie = 0;
      } else {
        ie = board[i - 1][j];
      }

      if (j == 0) {
        je = 0;
      } else {
        je = board[i][j - 1];
      }

      if (j == 0 or i == 0) {
        ije = 0;
      } else {
        ije = board[i - 1][j - 1];
      }

      board[i][j] = foo + ie + je - ije;
    }
  }

  long long q;
  cin >> q;

  for (long long foo = 0; foo < q; foo++) {
    long long lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    lx--;
    ly--;
    rx--;
    ry--;

    long long s = board[rx][ry];

    long long si, sj, sij;
    if (ly == 0) {
      si = 0;
    } else {
      si = board[rx][ly - 1];
    }

    if (lx == 0) {
      sj = 0;
    } else {
      sj = board[lx - 1][ry];
    }

    if (lx == 0 or ly == 0) {
      sij = 0;
    } else {
      sij = board[lx - 1][ly - 1];
    }

    cout << s - si - sj + sij << " ";
  }
}
