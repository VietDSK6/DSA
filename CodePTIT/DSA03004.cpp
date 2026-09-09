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

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end());

    long long x = 0, y = 0;

    for (int i = 0; i < n; i++) {   
        if (i % 2 == 0) {
            x = x  * 10 + a[i];
        } else {
            y = y * 10 + a[i];
        }
    }

    cout << x + y << "\n";
  }
}
