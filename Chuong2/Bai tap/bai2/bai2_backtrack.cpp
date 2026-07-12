#include <bits/stdc++.h>
using namespace std;

int n, k, b;
vector<int> arr;
vector<int> res;
vector<vector<int>> ans;

void Try(int n_remain, int s_remain, int last_i) {
  if (n_remain == 0 && s_remain == 0) {
    ans.push_back(res);
    return;
  }

  if (n_remain == 0 || s_remain < 0) {
    return;
  }

  if (n - last_i < n_remain) {
    return;
  }

  for (int i = last_i; i < n; i++) {
    res.push_back(arr[i]);
    Try(n_remain - 1, s_remain - arr[i], i + 1);
    res.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k >> b;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  Try(k, b, 0);

  cout << ans.size() << '\n';

  for (auto &v : ans) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << '\n';
  }

  return 0;
}
