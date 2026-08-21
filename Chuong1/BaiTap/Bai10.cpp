#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  cout << "Buoc 0: " << a[0] << '\n';

  for (int i = 1; i < n; i++) {
    int temp = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > temp) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = temp;
    cout << "Buoc " << i << ": ";
    for (int j = 0; j <= i; j++) {
      cout << a[j] << " ";
    }
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
