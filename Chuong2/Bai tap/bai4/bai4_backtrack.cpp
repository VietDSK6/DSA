#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;
vector<long long> cur;
vector<vector<long long>> ans;
vector<bool> used;

bool isPrime(long long x) {
  if (x < 2)
    return false;
  if (x == 2)
    return true;
  if (x % 2 == 0)
    return false;

  for (long long i = 3; i * i <= x; i += 2) {
    if (x % i == 0)
      return false;
  }

  return true;
}

bool checkLastK() {
  if ((int)cur.size() < k)
    return true;

  long long sum = 0;

  for (int i = cur.size() - k; i < (int)cur.size(); i++) {
    sum += cur[i];
  }

  return isPrime(sum);
}

void Try(int pos) {
  if (pos == n) {
    ans.push_back(cur);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = true;
      cur.push_back(a[i]);

      if (checkLastK()) {
        Try(pos + 1);
      }

      cur.pop_back();
      used[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  a.resize(n);
  used.assign(n, false);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  Try(0);

  cout << ans.size() << '\n';

  for (auto &v : ans) {
    for (long long x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}
