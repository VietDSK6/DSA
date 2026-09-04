#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];
vector<int> v;

bool prime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

void Try(int pos, int sum) {
  if (sum % 2 == 1) {
    for (int x : v)
      cout << x << ' ';
    cout << '\n';
  }

  for (int i = n - 1; i > pos; i--) {
    v.push_back(a[i]);
    Try(i, sum + a[i]);
    v.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a, a + n, greater<int>());

    v.clear();
    Try(-1, 0);
  }

  return 0;
}
