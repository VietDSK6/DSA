#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long b;
  cin >> n >> b;

  vector<long long> a(n), c(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }

  long long bestValue = 0;
  vector<int> bestX(n, 0);

  for (long long mask = 0; mask < (1LL << n); mask++) { // for 0 -> 2^n
    long long totalWeight = 0;
    long long totalValue = 0;
    vector<int> x(n, 0);

    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) { // Kiểm tra bit thứ i của mask có phải = 1 ko
        totalWeight += a[i];
        totalValue += c[i];
        x[i] = 1;
      }
    }

    if (totalWeight <= b && totalValue > bestValue) {
      bestValue = totalValue;
      bestX = x;
    }
  }

  cout << bestValue << '\n';

  for (int x : bestX) {
    cout << x << ' ';
  }

  return 0;
}
