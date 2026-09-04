#include <bits/stdc++.h>

using namespace std;

int n, k, a[100];
long long cnt = 0;

bool prime(long long x) {
  if (x < 2)
    return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

void Try(int i) {
  for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
    a[i] = j;

    if (i == k) {
      cnt++;

      if (prime(cnt)) {
        cout << cnt << ": ";
        for (int x = 1; x <= k; x++)
          cout << a[x] << ' ';
        cout << '\n';
      }
    } else {
      Try(i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  a[0] = 0;
  Try(1);

  return 0;
}
