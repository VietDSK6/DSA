#include <bits/stdc++.h>

using namespace std;

string base_convert(int a, int b) {
  string r = "";
  string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (a > 0) {
    r += digits[a % b];
    a /= b;
  }
  reverse(r.begin(), r.end());
  return r;
}

int main() {
  iostream::sync_with_stdio(false);
  int tc;
  cin >> tc;
  int a, b;
  for (int i = 0; i < tc; i++) {
    cin >> a >> b;
    cout << a << "  " << b << "   " << base_convert(a, b) << "\n";
  }
}
