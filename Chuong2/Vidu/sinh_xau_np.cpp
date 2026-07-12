#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int n, X[MAX], OK = 1, dem = 0;

void init() {
  cout << "\n Nhap n:";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    X[i] = 0;
  }
}

void result() {
  cout << "\n" << ++dem << ": ";
  for (int i = 1; i <= n; i++) {
    cout << X[i];
  }
}

void next_bin() {
  int i = n;
  while (i > 0 && X[i] != 0) {
    X[i] = 0;
    i--;
  }
  if (i > 0)
    X[i] = 1;
  else
    OK = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  while (OK) {
    result();
    next_bin();
  }
  return 0;
}
