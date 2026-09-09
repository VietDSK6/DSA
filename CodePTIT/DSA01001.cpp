#include <bits/stdc++.h>

using namespace std;

void next_bin(string k) {
  for (int i = k.length() - 1; i >= 0; i--) {
    if (k[i] == '0') {
      k[i] = '1';
      cout << k << "\n";
      return;
    }

    k[i] = '0';
  }

  cout << k << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    string k;
    cin >> k;
    next_bin(k);
  }
}
