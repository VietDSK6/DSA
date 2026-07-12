#include <bits/stdc++.h>
using namespace std;

int tong(int i) {
  if (i == 1)
    return 1;
  return i + tong(i - 1);
}

int tich(int i) {
  if (i == 0)
    return 1;
  return i * tich(i-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
