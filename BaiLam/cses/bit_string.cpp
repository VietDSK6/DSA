#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const long long MOD = 1'000'000'007;

  int n;
  cin >> n;

  long long answer = 1;

  for (int i = 0; i < n; i++) {
    answer = answer * 2 % MOD;
  }

  cout << answer << '\n';

  return 0;
}
