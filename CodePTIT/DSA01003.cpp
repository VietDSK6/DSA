#include <bits/stdc++.h>

using namespace std;

void next(vector<int> &arr, int n) {
  next_permutation(arr.begin(), arr.end());

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
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    next(arr, n);
  }
}
