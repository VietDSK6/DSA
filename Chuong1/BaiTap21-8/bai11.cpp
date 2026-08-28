#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void Try(int i) {
  if (i == n - 1) {
    if (s.back() == '6' && s[n - 2] == '6' && n >= 4 && s[n - 3] == '6' &&
        s[n - 4] == '6')
      return;

    s.push_back('6');
    cout << s << '\n';
    s.pop_back();
    return;
  }

  if (s.size() < 3 || !(s[s.size() - 1] == '6' && s[s.size() - 2] == '6' &&
                        s[s.size() - 3] == '6')) {
    s.push_back('6');
    Try(i + 1);
    s.pop_back();
  }

  if (s.back() != '8') {
    s.push_back('8');
    Try(i + 1);
    s.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  if (n < 6)
    return 0;

  s = "8";
  Try(1);

  return 0;
}
