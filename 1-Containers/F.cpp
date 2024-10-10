#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;

  stack<int> balls;
  stack<int> count_balls;

  int counter = 0;
  for (int i = 0; i < n; i++) {
    int ball;
    cin >> ball;

    if (i == 0) {
      balls.push(ball);
      count_balls.push(1);
    }

    else if (ball == balls.top()) {
      count_balls.push(count_balls.top() + 1);
      balls.push(ball);
    } else if (count_balls.top() >= 3) {
      int to_del = count_balls.top();
      counter += to_del;

      for (int foo = 0; foo < to_del; foo++) {
        count_balls.pop();
        balls.pop();
      }

      if (balls.size() > 0 and ball == balls.top()) {
        count_balls.push(count_balls.top() + 1);
      } else {
        count_balls.push(1);
      }

      balls.push(ball);
    } else {
      count_balls.push(1);
      balls.push(ball);
    }
  }

  if (count_balls.size() > 0 and count_balls.top() >= 3) {
    counter += count_balls.top();
  }

  cout << counter;

  return 0;
}
