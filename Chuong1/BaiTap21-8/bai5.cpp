#include <bits/stdc++.h>
using namespace std;

int n, a[100], cnt = 1;

bool sinh() {
  int i = n - 2;

  while (i >= 0 && a[i] > a[i + 1])
    i--;

  if (i < 0)
    return false;

  int j = n - 1;

  while (a[j] < a[i])
    j--;

  swap(a[i], a[j]);
  reverse(a + i + 1, a + n);

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }

  do {
      cout << cnt << ": ";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << '\n';
    cnt++;
  } while (sinh());

  return 0;
}
