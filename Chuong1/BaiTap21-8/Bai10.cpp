#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    set<int> old;

    for (int i = 0; i < k; i++) {
      cin >> a[i];
      old.insert(a[i]);
    }

    int i = k - 1;

    while (i >= 0 && a[i] == n - k + i + 1)
      i--;

    if (i < 0) {
      cout << k << '\n';
      continue;
    }

    a[i]++;

    for (int j = i + 1; j < k; j++) {
      a[j] = a[j - 1] + 1;
    }

    int cnt = 0;

    for (int x : a) {
      if (old.find(x) == old.end())
        cnt++;
    }

    cout << cnt << '\n';
  }

  return 0;
}
