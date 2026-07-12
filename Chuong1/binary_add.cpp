#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string Addition(string a, string b) {
  // Đảm bảo a và b có cùng độ dài bằng cách thêm số 0 vào đầu chuỗi ngắn hơn
  while (a.length() < b.length()) {
    a = "0" + a;
  }

  while (b.length() < a.length()) {
    b = "0" + b;
  }

  int n = a.length();
  string s = "";
  int c = 0; // số nhớ

  // Cộng từ phải sang trái
  for (int j = n - 1; j >= 0; j--) {
    int aj = a[j] - '0';
    int bj = b[j] - '0';

    int tong = aj + bj + c;

    int sj = tong % 2; // bit kết quả
    c = tong / 2;      // số nhớ mới

    s = char(sj + '0') + s;
  }

  // Nếu sau cùng vẫn còn nhớ thì thêm vào đầu
  if (c != 0) {
    s = char(c + '0') + s;
  }

  return s;
}

int main() {
  string a, b;

  cin >> a;
  cin >> b;

  string result = Addition(a, b);

  cout << result << endl;

  return 0;
}
