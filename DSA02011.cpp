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

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<vector<int>> res;

    while (!a.empty()) {
      res.push_back(a);

      vector<int> b;

      for (int i = 0; i < a.size() - 1; i++) {
        b.push_back(a[i] + a[i + 1]);
      }

      a = b;
    }

    for (int i = res.size() - 1; i >= 0; i--) {
      cout << "[";

      for (int j = 0; j < res[i].size(); j++) {
        cout << res[i][j];

        if (j != res[i].size() - 1)
          cout << " ";
      }

      cout << "]";

      if (i != 0)
        cout << " ";
    }

    cout << "\n";
  }
}
