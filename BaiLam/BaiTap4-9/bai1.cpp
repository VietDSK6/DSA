#include <bits/stdc++.h>

using namespace std;

int tong, cnt = 0;
int tien[] = {1,2,5,10, 20, 50, 100, 200, 500, 1000};

void solve(int tong) {
    for (int i = 9; i >= 0; i--) {
        while (tien[i] <= tong) {
            tong -= tien[i];
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    cnt = 0;
    cin >> tong;
    solve(tong);
  }
}
