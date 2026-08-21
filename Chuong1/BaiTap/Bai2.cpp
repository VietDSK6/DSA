#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &a, int l, int r) {
  if (l >= r)
    return;

  int pivot = a[r];
  int i = l - 1;

  for (int j = l; j < r; j++) {
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i + 1], a[r]);

  int p = i + 1;

  quickSort(a, l, p - 1);
  quickSort(a, p + 1, r);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  quickSort(a, 0, n - 1);
  int l = 0, r = n - 1;
  while (l <= r) {
    if (l == r) {
      cout << a[l] << " ";
    } else {
      cout << a[r] << " " << a[l];
    }
    l++;
    r--;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
}
