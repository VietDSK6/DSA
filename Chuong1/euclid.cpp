#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int gcd_recur(int a, int b) {
  if (b == 0)
    return a;
  return gcd_recur(b, a % b);
}

int lcm(int a, int b) {
  return (a / gcd(a, b) * b);
  // chia trước để phòng khi a * b bị tràn số
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << "\n";
  return 0;
}

// Euclid hoạt động vì phép chia lấy dư không làm thay đổi USCLN, nhưng làm số
// nhỏ dần, nên cuối cùng sẽ dừng ở đáp án.
// khi có số bằng 0 -> gcd (x, 0) = x = gcd (a, b)
