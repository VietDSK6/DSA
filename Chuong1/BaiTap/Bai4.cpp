#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &a, int l, int r) {
  int i = l, j = r;
  int pivot = a[(l + r) / 2];

  while (i <= j) {
    while (a[i] < pivot)
      i++;
    while (a[j] > pivot)
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
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);

  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  quickSort(a, 0, n - 1);
  quickSort(b, 0, m - 1);

  int i = 0, j = 0;

  while (i < n || j < m) {
    int x;

    if (j >= m || (i < n && a[i] < b[j])) {
      x = a[i++];
    } else if (i >= n || b[j] < a[i]) {
      x = b[j++];
    } else {
      x = a[i];
      i++;
      j++;
    }

    cout << x << " ";
    while (i < n && a[i] == x)
      i++;
    while (j < m && b[j] == x)
      j++;
  }

  cout << '\n';

  i = 0;
  j = 0;

  while (i < n && j < m) {
    if (a[i] < b[j]) {
      i++;
    } else if (a[i] > b[j]) {
      j++;
    } else {
      int x = a[i];
      cout << x << " ";

      while (i < n && a[i] == x)
        i++;
      while (j < m && b[j] == x)
        j++;
    }
  }

  cout << '\n';
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
