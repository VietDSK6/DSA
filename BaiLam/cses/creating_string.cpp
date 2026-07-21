#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int frequency[26];
vector<string> results;

void backtrack(string &current) {
  if ((int)current.size() == n) {
    results.push_back(current);
    return;
  }

  for (int i = 0; i < 26; ++i) {
    if (frequency[i] == 0) {
      continue;
    }

    current.push_back(char('a' + i));
    --frequency[i];

    backtrack(current);

    ++frequency[i];
    current.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  n = s.size();

  for (char c : s) {
    ++frequency[c - 'a'];
  }

  string current;
  backtrack(current);

  cout << results.size() << '\n';

  for (const string &permutation : results) {
    cout << permutation << '\n';
  }

  return 0;
}
