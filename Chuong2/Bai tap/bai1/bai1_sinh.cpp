#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  vector<vector<int>> ans;

  for (int mask = 0; mask < (1 << n); mask++) {  // = for (1 -> 2^n)
    int sum = 0;
    vector<int> cur;

    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {  // kiểm tra xem phần tử i có đc chọn không 
        sum += a[i];
        cur.push_back(a[i]);
      }
    }

    if (sum == k) {
      ans.push_back(cur);
    }
  }

  cout << ans.size() << '\n';

  for (auto &v : ans) {
    for (int x : v)
      cout << x << ' ';
    cout << '\n';
  }

  return 0;
}

// O(n * 2^n) cố định