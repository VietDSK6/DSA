#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end());

    long long sum = 0;

    for (int i = 0; i < n; i++) {
      sum = (sum + a[i] * i) % MOD;
    }

    cout << sum << "\n";
  }
}
