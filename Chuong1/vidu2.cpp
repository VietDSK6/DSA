#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long n) {
  if (n < 2)
    return false;
  if (n < 4)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

// Kiểm tra chữ số có là số nguyên tố (2, 3, 5, 7)
bool allDigitsPrime(long long n) {
  while (n > 0) {
    int d = n % 10;
    if (d != 2 && d != 3 && d != 5 && d != 7)
      return false;
    n /= 10;
  }
  return true;
}

// Tính tổng các chữ số
int sumDigits(long long n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

// Đảo ngược chữ số
long long reverseNum(long long n) {
  long long rev = 0;
  while (n > 0) {
    rev = rev * 10 + n % 10;
    n /= 10;
  }
  return rev;
}

void solve() {

  int M;
  if (!(cin >> M))
    return;

  while (M--) {
    int K;
    cin >> K;

    long long countN = 0;
    long long start = pow(10, K - 1);
    long long end = pow(10, K) - 1;

    for (long long N = start; N <= end; ++N) {
      // Điều kiện 1: N là số nguyên tố
      if (!isPrime(N))
        continue;

      // Điều kiện 2: Mỗi chữ số của N cũng là các số nguyên tố
      if (!allDigitsPrime(N))
        continue;

      // Điều kiện 3: Tổng các chữ số của N cũng là một số nguyên tố
      if (!isPrime(sumDigits(N)))
        continue;

      // Điều kiện 4: Đảo ngược các chữ số của N cũng là một số nguyên tố
      if (!isPrime(reverseNum(N)))
        continue;

      countN++;
    }
    cout << K << " " << countN << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
