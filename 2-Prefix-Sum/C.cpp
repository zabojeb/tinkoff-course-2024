#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> board;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      int foo;
      cin >> foo;

      int ie, je;
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

      row.push_back(foo + ie + je);
    }

    board.push_back(row);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  /*
    int q;
    cin >> q;

    for (int foo = 0; foo < q; foo++) {
      int lx, ly, rx, ry;
      cin >> lx >> ly >> rx >> ry;
  */
}
