// 1 2 3 4 5
// 1 2 3 5 4
// 1 2 4 3 5
// 1 2 4 5 4
// 1 3 2 4 5
// 2 1 3 4 5
#include <bits/stdc++.h>

#define MAX 100

using namespace std;

int n, X[MAX], dem = 0;
bool OK = true;

void init() {
  cout << "\n Nhap n: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    X[i] = i;
  }
}

void result() {
  cout << "\n" << ++dem << ": ";
  for (int i = 1; i <= n; i++) {
    cout << X[i] << " ";
  }
}
void next_hoan_vi() {
  int i = n - 1;

  while (i > 0 && X[i] > X[i + 1]) {
    i--;
  }

  if (i == 0) {
    OK = 0;
  } else {
    int j = n;

    while (X[j] < X[i]) {
      j--;
    }

    swap(X[i], X[j]);

    int l = i + 1;
    int r = n;

    while (l < r) {
      swap(X[l], X[r]);
      l++;
      r--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  while (OK) {
    result();
    next_hoan_vi();
  }
  return 0;
}
