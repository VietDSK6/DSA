#include <bits/stdc++.h>
using namespace std;

int n, k;
bool ok = true;

void sinh(vector<int> &a) {
  int i = k - 1;

  while (i >= 0 && a[i] == 1) {
    a[i] = 0;
    i--;
  }

  if (i >= 0)
    a[i] = 1;
  else
    ok = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    while (ok) {
      for (int i = 0; i < k; i++)
        cout << a[i] << " ";
      cout << '\n';

      sinh();
    }
  }
}
