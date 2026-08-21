#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
    cout << "Buoc " << i + 1 << ": ";
    for (int x : a)
      cout << x << " ";
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;

  while (tc--) {
    solve();
  }
}
