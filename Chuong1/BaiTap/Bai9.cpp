#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  for (int i = 0; i < n - 1; i++) {
    int minPos = i;

    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minPos]) {
        minPos = j;
      }
    }

    swap(a[i], a[minPos]);
    cout << "Buoc " << i+1 << ": ";
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
