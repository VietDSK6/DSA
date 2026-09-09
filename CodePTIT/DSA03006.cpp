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

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    bool ok = true;

    for (int i = 0; i < n / 2; i++) {
      int j = n - 1 - i;

      if (min(a[i], a[j]) != b[i] || max(a[i], a[j]) != b[j]) {
        ok = false;
        break;
      }
    }

    if (n % 2 && a[n / 2] != b[n / 2])
      ok = false;

    cout << (ok ? "Yes" : "No") << "\n";
  }
}
