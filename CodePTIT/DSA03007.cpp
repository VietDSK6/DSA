#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    for (int i = 0; i < n; i++)
      cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long sum = 0;

    for (int i = 0; i < n; i++)
      sum += a[i] * b[i];

    cout << sum << "\n";
  }
}
