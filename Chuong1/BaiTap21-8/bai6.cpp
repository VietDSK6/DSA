#include <bits/stdc++.h>
using namespace std;

bool sinh(string &s) {
  int i = s.size() - 1;

  while (i >= 0 && s[i] == 'B') {
    s[i] = 'A';
    i--;
  }

  if (i < 0)
    return false;

  s[i] = 'B';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    string s(k, 'A');

    do {
      cout << s << " ";
    } while (sinh(s));

    cout << '\n';
  }

  return 0;
}
