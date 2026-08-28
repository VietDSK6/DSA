#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[] = {3, 1, 5, 4, 2, 9, 6};
  int n = 7;
  for (int i = 1; i < n; i++) {
    int  k = arr[i];
    int j = i-1; 
    while (j >= 0 && arr[j] > k) {
        arr[j+1] = arr[j];
        j-=1;
    }
    arr[j+1] = k;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
}
