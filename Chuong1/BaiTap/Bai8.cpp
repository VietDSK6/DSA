#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;

bool check(int x, int y) {
  if (cnt[x] != cnt[y])
    return cnt[x] > cnt[y];

  return x < y;
}

void quickSort(vector<int> &a, int l, int r) {
  int i = l, j = r;
  int pivot = a[(l + r) / 2];

  while (i <= j) {
    while (check(a[i], pivot))
      i++;
    while (check(pivot, a[j]))
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
  int n;
  cin >> n;

  vector<int> a(n);
  cnt.clear();

  for (int &x : a) {
    cin >> x;
    cnt[x]++;
  }

  quickSort(a, 0, n - 1);

  for (int x : a)
    cout << x << " ";

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

  return 0;
}
