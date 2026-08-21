#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &a, int l, int r) {
  int i = l, j = r;
  int pivot = a[(l + r) / 2];

  while (i <= j) {
    while (a[i] > pivot)
      i++;
    while (a[j] < pivot)
      j--;

    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (l < j)
    quickSort(a, l, j);
  if (i < r)
    quickSort(a, i, r);
}

void solve() {
  int n, k;
  cin >> n >> k; 

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  quickSort(a, 0, n - 1);

  for (int i = 0; i < k; i++) {
      cout << a[i] << " ";
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
