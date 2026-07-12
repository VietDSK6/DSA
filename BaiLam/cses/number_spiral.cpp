#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long y, x;
    cin >> y >> x;

    long long answer;

    if (y > x) {
      if (y % 2 == 0)
        answer = y * y - x + 1;
      else
        answer = (y - 1) * (y - 1) + x;
    } else {
      if (x % 2 == 1)
        answer = x * x - y + 1;
      else
        answer = (x - 1) * (x - 1) + y;
    }

    cout << answer << '\n';
  }
}
