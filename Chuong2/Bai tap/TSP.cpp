#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> c(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }

  const long long INF = 1e18;

  int totalMask = 1 << n;

  vector<vector<long long>> dp(totalMask, vector<long long>(n, INF));

  // Xuất phát tại thành phố 0
  dp[1][0] = 0;

  for (int mask = 0; mask < totalMask; mask++) {

    for (int u = 0; u < n; u++) {

      if (dp[mask][u] == INF)
        continue;

      // Thử đi tới thành phố v chưa thăm
      for (int v = 0; v < n; v++) {

        if (mask & (1 << v))
          continue;

        int newMask = mask | (1 << v);

        dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + c[u][v]);
      }
    }
  }

  int fullMask = (1 << n) - 1;

  long long answer = INF;

  for (int u = 1; u < n; u++) {
    answer = min(answer, dp[fullMask][u] + c[u][0]);
  }

  cout << answer << '\n';

  return 0;
}
