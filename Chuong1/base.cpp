#include <bits/stdc++.h>
using namespace std;

string convertBase(int n, int b) {
  if (n == 0)
    return "0";

  string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string res = "";

  while (n > 0) {
    int r = n % b;
    res += digits[r];
    n /= b;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  cout << convertBase(a, b);

  return 0;
}

// mỗi lần chia cho b, ta tách ra một chữ số của n trong hệ cơ số b, bắt đầu từ
// chữ số thấp nhất.
//
