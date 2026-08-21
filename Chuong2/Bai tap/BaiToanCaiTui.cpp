#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int value;
  double ratio;
};

int n, M;
vector<Item> a;

vector<int> x;     // phương án đang xét
vector<int> bestX; // phương án tốt nhất

int bestValue = 0;

// Tính cận trên của nhánh hiện tại
double bound(int i, int currentWeight, int currentValue) {
  if (currentWeight > M)
    return 0;

  double g = currentValue;
  int weight = currentWeight;

  // Thử lấy trọn các vật còn lại
  while (i < n && weight + a[i].weight <= M) {
    weight += a[i].weight;
    g += a[i].value;
    i++;
  }

  // Nếu vật tiếp theo không lấy trọn được
  // thì lấy một phần để tính cận trên
  if (i < n) {
    int remain = M - weight;
    g += remain * a[i].ratio;
  }

  return g;
}

void branchAndBound(int i, int currentWeight, int currentValue) {
  // Đã xét hết n vật
  if (i == n) {
    if (currentValue > bestValue) {
      bestValue = currentValue;
      bestX = x;
    }
    return;
  }

  // Nếu cận trên không thể vượt best hiện tại
  // => cắt nhánh
  if (bound(i, currentWeight, currentValue) <= bestValue)
    return;

  // =========================
  // Nhánh 1: lấy vật i
  // =========================
  if (currentWeight + a[i].weight <= M) {
    x[i] = 1;

    branchAndBound(i + 1, currentWeight + a[i].weight,
                   currentValue + a[i].value);
  }

  // =========================
  // Nhánh 2: không lấy vật i
  // =========================
  x[i] = 0;

  branchAndBound(i + 1, currentWeight, currentValue);
}

int main() {
  cin >> n >> M;

  a.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].weight >> a[i].value;
    a[i].ratio = (double)a[i].value / a[i].weight;
  }

  // Sắp xếp giảm dần theo value / weight
  sort(a.begin(), a.end(),
       [](const Item &A, const Item &B) { return A.ratio > B.ratio; });

  x.assign(n, 0);
  bestX.assign(n, 0);

  branchAndBound(0, 0, 0);

  cout << "Gia tri lon nhat: " << bestValue << '\n';

  cout << "Cac vat duoc chon:\n";

  for (int i = 0; i < n; i++) {
    if (bestX[i]) {
      cout << "weight = " << a[i].weight << ", value = " << a[i].value << '\n';
    }
  }

  return 0;
}
