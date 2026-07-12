#include <bits/stdc++.h>
using namespace std;

int n, k, b;
vector<int> arr;
vector<int> res;
vector<vector<int>> ans;
vector<int> prefix;

int sumRange(int l, int r) {
  // tổng arr[l] + arr[l + 1] + ... + arr[r - 1]
  return prefix[r] - prefix[l];
}

void Try(int n_remain, int s_remain, int last_i) {
  if (n_remain == 0 && s_remain == 0) {
    ans.push_back(res);
    return;
  }

  if (n_remain == 0)
    return;
  if (s_remain < 0)
    return;

  // Không còn đủ phần tử để chọn
  if (n - last_i < n_remain)
    return;

  // Cận dưới: chọn n_remain số nhỏ nhất còn lại
  int minPossible = sumRange(last_i, last_i + n_remain);

  if (minPossible > s_remain)
    return;

  // Cận trên: chọn n_remain số lớn nhất còn lại
  int maxPossible = sumRange(n - n_remain, n);

  if (maxPossible < s_remain)
    return;

  for (int i = last_i; i <= n - n_remain; i++) {
    // Vì arr đã sort tăng dần, nếu arr[i] > s_remain thì các số sau càng lớn
    if (arr[i] > s_remain)
      break;

    res.push_back(arr[i]);
    Try(n_remain - 1, s_remain - arr[i], i + 1);
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

  sort(arr.begin(), arr.end());

  prefix.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
  }

  Try(k, b, 0);

  cout << ans.size() << '\n';

  for (auto &v : ans) {
    for (int x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}

// backtrack nhưng thêm nhiều case để cắt nhánh sớm
//
