#include <bits/stdc++.h>
using namespace std;

int n;
long long dem = 0;

void hanoi(int n, char from, char to, char temp) {
  if (n == 1) {
    cout << "Chuyen dia 1 tu " << from << " sang " << to << '\n';
    dem++;
    return;
  }

  // Chuyen n - 1 dia tu from sang temp
  hanoi(n - 1, from, temp, to);

  // Chuyen dia lon nhat tu from sang to
  cout << "Chuyen dia " << n << " tu " << from << " sang " << to << '\n';
  dem++;

  // Chuyen n - 1 dia tu temp sang to
  hanoi(n - 1, temp, to, from);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  hanoi(n, 'A', 'B', 'C');

  cout << "Tong so buoc: " << dem << '\n';

  return 0;
}
