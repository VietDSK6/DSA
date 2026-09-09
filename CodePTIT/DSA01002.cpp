#include <bits/stdc++.h>

using namespace std;

void next(vector<int> &arr, int n, int k) {
  bool ok = false;

  for (int i = k - 1; i >= 0; i--) {
    if (arr[i] != n - k + i + 1) {
      arr[i]++;

      for (int j = i + 1; j < k; j++) {
        arr[j] = arr[j - 1] + 1;
      }

      ok = true;
      break;
    }
  }

  if (!ok) {
    for (int i = 0; i < k; i++) {
      arr[i] = i + 1;
    }
  }

  for (int x : arr) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    vector<int> arr(k);

    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }

    next(arr, n, k);
  }
}