#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
vector<bool> used;
int dem = 0;

void result() {
  cout << ++dem << ": ";
  for (int v : x) {
    cout << v << ' ';
  }
  cout << '\n';
}

void Try(int pos) {
  if (pos == n) {
    result();
    return;
  }

  for (int value = 1; value <= n; value++) {
    if (!used[value]) {
      x.push_back(value);
      used[value] = true;

      Try(pos + 1);

      used[value] = false;
      x.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  used.assign(n + 1, false);

  Try(0);

  return 0;
}
