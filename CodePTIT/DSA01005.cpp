#include <bits/stdc++.h>

using namespace std;
int n, a[100], k;
bool OK = true;
void in() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      cnt++;
  }
  if (cnt != k)
    return;
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  cout << "\n";
}

void sinh() {
  int i = n - 1;
  while (i >= 0 && a[i] == 1) {
    a[i] = 0;
    i--;
  }

  if (i < 0) {
    OK = false;
  } else {
    a[i] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      a[i] = 0;
    while (OK) {
      in();
      sinh();
    }
    OK = true;
  }
}
