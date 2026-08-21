#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, X;
  cin >> n >> X;

  vector<int> a(n);

  for (int &x : a)
    cin >> x;

  for (int i = 1; i < n; i++) {
    int tmp = a[i];
    int j = i - 1;

    while (j >= 0 && abs(a[j] - X) > abs(tmp - X)) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = tmp;
  }

  for (int x : a) {
    cout << x << " ";
  }

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
}
