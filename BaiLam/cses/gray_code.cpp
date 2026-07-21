#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> grayCode = {"0", "1"};

  for (int length = 2; length <= n; ++length) {
    int currentSize = grayCode.size();

    for (int i = currentSize - 1; i >= 0; --i) {
      grayCode.push_back(grayCode[i]);
    }

    for (int i = 0; i < currentSize; ++i) {
      grayCode[i] = '0' + grayCode[i];
    }

    for (int i = currentSize; i < 2 * currentSize; ++i) {
      grayCode[i] = '1' + grayCode[i];
    }
  }

  for (const string &code : grayCode) {
    cout << code << '\n';
  }

  return 0;
}
