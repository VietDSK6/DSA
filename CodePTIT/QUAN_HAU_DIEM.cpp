#include <bits/stdc++.h>

using namespace std;

int a[8][8];
bool col[8], d1[15], d2[15];
int res;

void backtrack(int row, int sum) {
  if (row == 8) {
    res = max(res, sum);
    return;
  }

  for (int j = 0; j < 8; j++) {
    if (!col[j] && !d1[row - j + 7] && !d2[row + j]) {
      col[j] = true;
      d1[row - j + 7] = true;
      d2[row + j] = true;

      backtrack(row + 1, sum + a[row][j]);

      col[j] = false;
      d1[row - j + 7] = false;
      d2[row + j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cin >> a[i][j];
      }
    }

    memset(col, false, sizeof(col));
    memset(d1, false, sizeof(d1));
    memset(d2, false, sizeof(d2));

    res = 0;

    backtrack(0, 0);

    cout << "Test " << tc << ": " << res << "\n";
  }
}
