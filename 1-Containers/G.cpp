#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N;
  cin >> N;

  int time = 0;

  queue<int> q;

  for (int i = 0; i < N; i++) {
    int h, m, anger;
    cin >> h >> m >> anger;

    int arrival_time = h * 60 + m;

    while (!q.empty() and q.front() <= arrival_time) {
      q.pop();
    }

    if ((int)q.size() > anger) {
      int h = arrival_time / 60;
      int m = arrival_time % 60;
      cout << h << " " << m << endl;
    } else {
      if (time < arrival_time) {
        time = arrival_time;
      }

      time += 20;

      int h = time / 60;
      int m = time % 60;
      cout << h << " " << m << endl;

      q.push(time);
    }
  }

  return 0;
}
