#include <bits/stdc++.h>
using namespace std;

int n, k, b;
vector<int> arr;
vector<int> res;
vector<vector<int>> ans;

vector<vector<vector<bool>>> dp;

void trace(int i, int cnt, int sum) {
  if (cnt == 0 && sum == 0) {
    ans.push_back(res);
    return;
  }

  if (i == n)
    return;

  // Nhánh không chọn arr[i]
  if (dp[i + 1][cnt][sum]) {
    trace(i + 1, cnt, sum);
  }

  // Nhánh chọn arr[i]
  if (cnt > 0 && sum >= arr[i] && dp[i + 1][cnt - 1][sum - arr[i]]) {
    res.push_back(arr[i]);
    trace(i + 1, cnt - 1, sum - arr[i]);
    res.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k >> b;

  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  dp.assign(n + 1, vector<vector<bool>>(k + 1, vector<bool>(b + 1, false)));

  dp[n][0][0] = true;

  for (int i = n - 1; i >= 0; i--) {
    for (int cnt = 0; cnt <= k; cnt++) {
      for (int sum = 0; sum <= b; sum++) {
        // Không chọn arr[i]
        dp[i][cnt][sum] = dp[i + 1][cnt][sum];

        // Chọn arr[i]
        if (cnt > 0 && sum >= arr[i]) {
          dp[i][cnt][sum] = dp[i][cnt][sum] || dp[i + 1][cnt - 1][sum - arr[i]];
        }
      }
    }
  }

  trace(0, k, b);

  cout << ans.size() << '\n';

  for (auto &v : ans) {
    for (int x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}
