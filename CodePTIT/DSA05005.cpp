#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
  int n;
  cin >> n;

  vector<long long> a(n), dp(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  dp[0] = a[0];

  if (n > 1) {
    dp[1] = max(a[0], a[1]);
  }

  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
  }

  cout << dp[n - 1] << "\n";
  }
  return 0;
}