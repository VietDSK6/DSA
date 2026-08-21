#include <bits/stdc++.h>

using namespace std;

int maxSumSubArr(int a[], int n) {
  int realMax = 0, currentMax = 0;
  for (int i = 0; i < n; i++) {
    currentMax += a[i];
    if (currentMax < 0)
      currentMax = 0;
    if (currentMax > realMax) {
      realMax = currentMax;
    }
  }
  return realMax;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
}
