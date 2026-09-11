#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = 1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  do {
    cout << cnt << ": ";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    cnt++;
  } while (next_permutation(a.begin(), a.end()));
}
