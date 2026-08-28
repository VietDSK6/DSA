#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], x[100];
long long cnt = 0;

void Try(int pos, int start) {
  if (pos == k) {
    cnt++;
    return;
  }

  for (int i = start; i < n; i++) {
    if (pos == 0 || a[i] > a[x[pos - 1]]) {
      x[pos] = i;
      Try(pos + 1, i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  Try(0, 0);

  cout << cnt;

  return 0;
}
