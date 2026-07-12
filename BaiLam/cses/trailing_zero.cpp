#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  long long answer = 0;

  while (n > 0) {
    n /= 5;
    answer += n;
  }

  cout << answer << '\n';

  return 0;
}
