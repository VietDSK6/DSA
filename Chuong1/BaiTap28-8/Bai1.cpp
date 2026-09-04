#include <bits/stdc++.h>

using namespace std;

int a[8][8];
bool col[8], d1[15], d2[15];
long long ans = LLONG_MIN;

void Try(int row, long long sum) {
  if (row == 8) {
    ans = max(ans, sum);
    return;
  }

  for (int j = 0; j < 8; j++) {
    int x = row - j + 7;
    int y = row + j;

    if (!col[j] && !d1[x] && !d2[y]) {
      col[j] = d1[x] = d2[y] = true;

      Try(row + 1, sum + a[row][j]);

      col[j] = d1[x] = d2[y] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tcs;
  cin >> tcs;
  for (int tc = 0; tc < tcs; tc++) {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        cin >> a[i][j];

    ans = LLONG_MIN;
    Try(0, 0);

    cout << "Test " << tc + 1 << ": " << ans << "\n";
  }

  return 0;
}
