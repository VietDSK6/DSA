#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  vector<int> arr(tc), dp(tc, 1);
  for (int i = 0; i < tc; i++) {
    cin >> arr[i];
  }
  int res = 0;
  for (int i = 0; i < tc; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}
