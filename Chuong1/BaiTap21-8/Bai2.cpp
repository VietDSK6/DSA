#include <bits/stdc++.h>
using namespace std;

int n, a[100], x[100], k, cnt = 0;
bool ok = true;

void sinh() {
  int i = n - 1;
  while (i >= 0 && x[i] == 1) {
    x[i] = 0;
    i--;
  }
  if (i >= 0)
    x[i] = 1;
  else
    ok = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  while (ok) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
      if (x[i])
        sum += a[i];
    }

    if (sum == k) {
      for (int i = 0; i < n; i++) {
        if (x[i])
          cout << a[i] << " ";
      }
      cnt++;
      cout << '\n';
    }

    sinh();
  }
  cout << cnt;
}
