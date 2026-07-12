#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, b;
  cin >> n >> b;

  vector<int> a(n + 1);
  vector<long long> c(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> c[i];
  }

  vector<vector<long long>> dp(n + 1, vector<long long>(b + 1, 0));
  vector<vector<int>> take(n + 1, vector<int>(b + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= b; w++) {
      // Không chọn vật i
      dp[i][w] = dp[i - 1][w]; // i - 1 vì đây là bài toán cái túi 0 /1
                               // nếu là i thì sẽ là bài toán cái túi 0 giới hạn

      // Chọn vật i
      if (w >= a[i]) {
        long long newValue = dp[i - 1][w - a[i]] + c[i];

        if (newValue > dp[i][w]) {
          dp[i][w] = newValue;
          take[i][w] = 1;
        }
      }
    }
  }

  cout << dp[n][b] << '\n';

  vector<int> x(n + 1, 0);
  int w = b;

  for (int i = n; i >= 1; i--) {
    if (take[i][w]) {
      x[i] = 1;
      w -= a[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << x[i] << ' ';
  }

  return 0;
}
