#include <bits/stdc++.h>

using namespace std;

void prev_bin(string s) {
  bool isFirst = true;
  for (int i = s.length(); i >= 0; i--) {
    if (s[i] == '1') {
      s[i] = '0';
      for (int j = i + 1; j < s.length(); j++) {
        s[j] = '1';
      }
      isFirst = false;
      break;
    }
  }
  if (isFirst) {
    for (int i = 0; i < s.length(); i++) {
      cout << '1';
    }
  } else {
    cout << s;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    string s;
    cin >> s;
    prev_bin(s);
  }
}
