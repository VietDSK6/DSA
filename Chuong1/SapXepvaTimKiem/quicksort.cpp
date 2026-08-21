#include <iostream>
using namespace std;

int partition(int a[], int left, int right) {
  int pivot = a[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[right]);

  return i + 1;
}

void quickSort(int a[], int left, int right) {
  if (left >= right)
    return;

  int pivotIndex = partition(a, left, right);

  quickSort(a, left, pivotIndex - 1);
  quickSort(a, pivotIndex + 1, right);
}

int main() {
  int a[] = {7, 2, 1, 6, 8, 5, 3, 4};
  int n = sizeof(a) / sizeof(a[0]);

  quickSort(a, 0, n - 1);

  for (int x : a) {
    cout << x << " ";
  }

  return 0;
}
