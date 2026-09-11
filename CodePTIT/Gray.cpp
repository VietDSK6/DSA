#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<string> gray;

    gray.push_back("0");
    gray.push_back("1");

    for (int len = 2; len <= n; len++) {
      int size = gray.size();

      for (int i = size - 1; i >= 0; i--) {
        gray.push_back(gray[i]);
      }

      for (int i = 0; i < size; i++) {
        gray[i] = "0" + gray[i];
      }

      for (int i = size; i < gray.size(); i++) {
        gray[i] = "1" + gray[i];
      }
    }

    for (int i = 0; i < gray.size(); i++) {
      cout << gray[i];

      if (i != gray.size() - 1)
        cout << " ";
    }

    cout << "\n";
  }
}
