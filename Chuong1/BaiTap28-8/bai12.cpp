#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll k, ans;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void Try(int pos, int mx, ll div, ll value) {
  if (div == k) {
    ans = min(ans, value);
    return;
  }

  ll cur = value;

  for (int e = 1; e <= mx; e++) {
    if (cur > ans / p[pos])
      break;

    cur *= p[pos];

    if (div > k / (e + 1))
      break;
    if (k % (div * (e + 1)) != 0)
      continue;

    Try(pos + 1, e, div * (e + 1), cur);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> k;

    ans = LLONG_MAX;

    Try(0, 63, 1, 1);

    cout << ans << "\n";
  }
  return 0;
}
