#include <bits/stdc++.h>

using namespace std;

string s, res;
bool used[256];

void Try() {
  if (res.size() == s.size()) {
    cout << res << ' ';
    return;
  }

  for (char c : s) {
    if (!used[c]) {
      used[c] = true;
      res += c;

      Try();

      res.pop_back();
      used[c] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s;

    sort(s.begin(), s.end());

    Try();
    cout << "\n";
  }
  return 0;
}
