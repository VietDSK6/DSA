#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b) {
  if ((a + b) % 3 != 0) {
    cout << "NO" << "\n";
    return;
  }
  if (max(a, b) > 2 * min(a, b)) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  int a, b;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    solve(a, b);
  }

  return 0;
}
