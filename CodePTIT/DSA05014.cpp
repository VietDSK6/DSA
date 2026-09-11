#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % MOD;
      }
    }

    cout << dp[n] << "\n";
  }

  return 0;
}
