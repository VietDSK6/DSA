#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int n, k, X[MAX], dem = 0;
bool OK = true;

void init() {
  cout << "\n Nhap n: ";
  cin >> n;
  cout << "\n Nhap k: ";
  cin >> k;
  for (int i = 1; i <= k; i++) {
    X[i] = i;
  }
}

void result() {
  cout << "\n" << ++dem << ": ";
  for (int i = 1; i <= k; i++) {
    cout << X[i] << " ";
  }
}

void next_to_hop() {
  int i = k;
  while (i > 0 && X[i] == n - k + i)
    i--;
  if (i > 0) {
    X[i] += 1;
    for (int j = i + 1; j <= k; j++) {
      X[j] = X[i] + j - i;
    }
  } else
    OK = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  while (OK) {
    result();
    next_to_hop();
  }
}
