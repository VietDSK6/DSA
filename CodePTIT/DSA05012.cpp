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
    vector<vector<int>> dp(1001, vector<int>(1001));
    for (int i = 0; i <= 1000; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || i == j) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
      }
    }
    cout << dp[n][k] << "\n";
  }

  return 0;
}
