#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
vector<bool> col, diag1, diag2;
int dem = 0;

void printResult() {
  cout << "Cach " << ++dem << ": ";

  for (int row = 1; row <= n; row++) {
    cout << x[row] << ' ';
  }

  cout << '\n';

  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      if (x[row] == col) {
        cout << " X ";
        continue;
      }
      cout << " . ";
    }
    cout << "\n";
  }
}

void Try(int row) {
  if (row > n) {
    printResult();
    return;
  }

  for (int c = 1; c <= n; c++) {
    if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
      x[row] = c;

      col[c] = true;
      diag1[row - c + n] =
          true;              // đường chéo chính có hiệu = nhau (+n để k bị âm)
      diag2[row + c] = true; // đường chéo phụ có tổng = nhau

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

  cin >> n;

  x.assign(n + 1, 0);
  col.assign(n + 1, false);
  diag1.assign(2 * n + 1, false);
  diag2.assign(2 * n + 1, false);

  Try(1);

  cout << "Tong so cach: " << dem << '\n';

  return 0;
}
