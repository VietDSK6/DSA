#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    long long S;
    cin >> n >> S;

    vector<long long> a(n);
    for (auto &x : a)
      cin >> x;

    int m = n / 2;
    int k = n - m;

    unordered_map<long long, int> right;

    for (int mask = 0; mask < (1 << k); mask++) {
      long long sum = 0;
      int cnt = 0;

      for (int i = 0; i < k; i++) {
        if (mask & (1 << i)) {
          sum += a[m + i];
          cnt++;
        }
      }

      if (!right.count(sum) || cnt < right[sum])
        right[sum] = cnt;
    }

    int ans = INT_MAX;

    for (int mask = 0; mask < (1 << m); mask++) {
      long long sum = 0;
      int cnt = 0;

      for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) {
          sum += a[i];
          cnt++;
        }
      }

      long long need = S - sum;

      if (right.count(need))
        ans = min(ans, cnt + right[need]);
    }

    if (ans == INT_MAX)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }

  return 0;
}
