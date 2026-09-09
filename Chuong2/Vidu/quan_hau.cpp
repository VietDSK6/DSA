#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
vector<bool> col, diag1, diag2;
int dem;

void Try(int row) {
  if (row > n) {
    dem++;
    return;
  }

  for (int c = 1; c <= n; c++) {
    if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
      x[row] = c;

      col[c] = true;
      diag1[row - c + n] = true;
      diag2[row + c] = true;

      Try(row + 1);

      col[c] = false;
      diag1[row - c + n] = false;
      diag2[row + c] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    dem = 0;
    cin >> n;

    x.assign(n + 1, 0);
    col.assign(n + 1, false);
    diag1.assign(2 * n + 1, false);
    diag2.assign(2 * n + 1, false);

    Try(1);
    cout << dem << "\n";
  }
  return 0;
}
