#include <bits/stdc++.h>

using namespace std;

void next(vector<int> &a, int n, int k, bool &ok) {
  int i = k - 1;

  while (i >= 0 && a[i] == n - k + i + 1) {
    i--;
  }

  if (i < 0) {
    ok = false;
    return;
  }

  a[i]++;

  for (int j = i + 1; j < k; j++) {
    a[j] = a[j - 1] + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);

    for (int i = 0; i < k; i++) {
      a[i] = i + 1;
    }

    bool ok = true;

    while (ok) {
      for (int x : a) {
        cout << x;
      }

      cout << " ";

      next(a, n, k, ok);
    }

    cout << "\n";
  }
}
