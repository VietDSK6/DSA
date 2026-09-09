#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  if (cin >> tc) {
    while (tc--) {
      int n;
      cin >> n;

      vector<int> arr(n);
      int a = 0, b = 0;

      for (int i = 0; i < n; i++) {
        cin >> arr[i];
      }

      sort(arr.begin(), arr.end());

      int mid = arr.size() / 2;
      int cnt = 1;
      for (int i = arr.size() - 1; i >= 0; i -= 2) {
        // if (arr[i] == 0)
        //   continue;
        a += cnt * arr[i];
        // cout << a << "\n";
        cnt *= 10;
      }
      cnt = 1;
      for (int i = arr.size() - 2; i >= 0; i -= 2) {
        // if (arr[i] == 0)
        //   continue;
        b += cnt * arr[i];
        // cout << b << "\n";
        cnt *= 10;
      }

      cout << a + b << "\n";
    }
  }
  return 0;
}
