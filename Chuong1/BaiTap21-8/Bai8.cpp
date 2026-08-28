#include <bits/stdc++.h>
using namespace std;

bool sinh(string &s) {
  int n = s.size();
  int i = n - 2;

  while (i >= 0 && !(s[i] == '0' && s[i + 1] == '1'))
    i--;

  if (i < 0)
    return false;

  swap(s[i], s[i + 1]);
  reverse(s.begin() + i + 2, s.end());

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s(n - k, '0');
    s += string(k, '1');

    do {
      cout << s << "\n";
    } while (sinh(s));
  }

  return 0;
}
