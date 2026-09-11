#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> a;
void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] != '#')
    return;

  a[i][j] = '.';

  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  a.resize(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        cnt++;
        dfs(i, j);
      }
    }
  }

  cout << cnt;
}
