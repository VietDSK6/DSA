#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[] = {3, 1, 5, 4, 2, 9, 6};
  int n = 7;
  for (int i = 0; i < n; i++) {
      bool check  = false;
      for (int j = 0; j < n-i-1; j++) {
          if (arr[j] > arr[j+1])   {
              check = true;
              swap(arr[j], arr[j+1]);
          }
      }
      if  (!check) break;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
}
