#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
  int n = s.length();
  map<char, int> freq;
  for (char c : s)
    freq[c]++;

  char max_char;
  int max_freq = 0;
  for (auto const &[key, val] : freq) {
    if (val > max_freq) {
      max_freq = val;
      max_char = key;
    }
  }

  if (max_freq > (n + 1) / 2)
    return "";

  string res(n, ' ');
  int idx = 0;

  while (max_freq > 0) {
    res[idx] = max_char;
    idx += 2;
    max_freq--;
  }
  freq[max_char] = 0;

  for (auto const &[key, val] : freq) {
    int count = val;
    while (count > 0) {
      if (idx >= n)
        idx = 1;
      res[idx] = key;
      idx += 2;
      count--;
    }
  }
  return res;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    if (solve(s) == "")
      cout << -1 << "\n";
    else
      cout << 1 << "\n";
  }
  return 0;
}
