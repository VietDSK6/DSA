#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    while (!a.empty()) {
      cout << "[";
      for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1)
          cout << " ";
      }
      cout << "]\n";

      vector<int> b;

      for (int i = 0; i + 1 < a.size(); i++)
        b.push_back(a[i] + a[i + 1]);

      a = b;
    }
  }
}
