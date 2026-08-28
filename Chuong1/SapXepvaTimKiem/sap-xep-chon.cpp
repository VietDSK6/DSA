#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[] = {3, 1, 5, 4, 2, 9, 6};
  int n = 7;
  for (int i = 0; i < n - 1; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[k] > arr[j]) {
        k = j;
      }
    }
    int temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
}
