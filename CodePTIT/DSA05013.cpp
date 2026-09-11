#include <bits/stdc++.h>

const long long MOD = 1e9 + 7;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k && j <= i; j++) {
        dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
    cout << dp[n] << "\n";
  }
}
