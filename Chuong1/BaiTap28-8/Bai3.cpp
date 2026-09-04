#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<string> v;
int a[100];

void Try(int i) {
  for (int j = a[i - 1] + 1; j <= (int)v.size() - k + i; j++) {
    a[i] = j;

    if (i == k) {
      for (int x = 1; x <= k; x++) {
        cout << v[a[x] - 1];
        if (x < k)
          cout << ' ';
      }
      cout << '\n';
    } else {
      Try(i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  set<string> s;

  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    s.insert(x);
  }

  for (auto x : s)
    v.push_back(x);

  a[0] = 0;
  Try(1);

  return 0;
}
