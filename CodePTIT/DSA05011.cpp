#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    if (k > 9 * n || k == 0) {
      cout << 0 << "\n";
      continue;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int d = 1; d <= 9 && d <= k; d++) {
      dp[1][d] = 1;
    }

    for (int i = 2; i <= n; i++) {
      for (int sum = 0; sum <= k; sum++) {
        for (int d = 0; d <= 9; d++) {
          if (sum >= d) {
            dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - d]) % MOD;
          }
        }
      }
    }

    cout << dp[n][k] << "\n";
  }

  return 0;
}
