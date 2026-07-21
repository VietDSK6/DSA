#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  vector<int> frequency(26, 0);

  for (char c : s) {
    frequency[c - 'A']++;
  }

  int oddCount = 0;
  char middleCharacter;

  for (int i = 0; i < 26; i++) {
    if (frequency[i] % 2 == 1) {
      oddCount++;
      middleCharacter = char('A' + i);
    }
  }

  if (oddCount > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  string leftHalf;

  for (int i = 0; i < 26; i++) {
    leftHalf += string(frequency[i] / 2, char('A' + i));
  }

  string rightHalf = leftHalf;
  reverse(rightHalf.begin(), rightHalf.end());

  cout << leftHalf;

  if (oddCount == 1) {
    cout << middleCharacter;
  }

  cout << rightHalf << '\n';
}
