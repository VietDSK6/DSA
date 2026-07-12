#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
vector<int> res;
vector<vector<int>> ans;

void Try(int remain, int last_i) {
  if (remain == 0) {
    ans.push_back(res);
    return;
  }

  if (remain < 0) {
    return;
  }

  for (int i = last_i; i < n; i++) {
    res.push_back(arr[i]);
    Try(remain - arr[i], i + 1);
    res.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  Try(k, 0);

  cout << ans.size() << '\n';

  for (auto v : ans) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << '\n';
  }

  return 0;
}

// Backtrack:  worst-case O(2^n), nhưng nếu tính in/copy kết quả thì cũng có thể
// lên O(n * 2^n)
