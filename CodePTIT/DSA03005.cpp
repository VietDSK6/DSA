#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end());

    k = min(k, n - k);
    long long x = 0, y = 0;

    for (int i = 0; i < k; i++) {
      x += a[i];
    }
    for (int i = k; i < n; i++) {
      y += a[i];
    }

    cout << y - x << "\n";
  }
}
