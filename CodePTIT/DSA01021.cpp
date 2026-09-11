#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;
    int arr[k];
    set<int> old;
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
      old.insert(arr[i]);
    }
    int i = k - 1;
    while (i >= 0 && arr[i] == n - k + i + 1) {
      i--;
    }
    if (i < 0) {
      cout << k << "\n";
      continue;
    }
    arr[i]++;
    for (int j = i + 1; j < k; j++) {
      arr[j] = arr[j - 1] + 1;
    }
    int cnt = 0;
    for (int x : arr) {
      if (!old.count(x)) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}
