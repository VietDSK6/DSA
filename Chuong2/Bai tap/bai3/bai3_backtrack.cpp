#include <bits/stdc++.h>
using namespace std;

int n;
long long b;
vector<long long> a, c;
vector<int> x, bestX;
long long bestValue = 0;

void Try(int i, long long currentWeight, long long currentValue) {
  if (i == n) {
    if (currentWeight <= b && currentValue > bestValue) {
      bestValue = currentValue;
      bestX = x;
    }
    return;
  }

  // Chọn vật i nếu không vượt túi
  if (currentWeight + a[i] <= b) {
    x[i] = 1;
    Try(i + 1, currentWeight + a[i], currentValue + c[i]);
  }

  // Không chọn vật i
  x[i] = 0;
  Try(i + 1, currentWeight, currentValue);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> b;

  a.resize(n);
  c.resize(n);
  x.assign(n, 0);
  bestX.assign(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }

  Try(0, 0, 0);

  cout << bestValue << '\n';

  for (int v : bestX) {
    cout << v << ' ';
  }

  return 0;
}
