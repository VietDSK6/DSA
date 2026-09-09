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

    for (int &x : a) {
      cin >> x;
    }

    for (int i = 0; i < n / 2; i++) {
      if (a[i] > a[n - i - 1]) {
        swap(a[i], a[n - i - 1]);
      }
    }

    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << '\n';
  }
}
