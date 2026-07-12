#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  long long totalSum = n * (n + 1) / 2;

  if (totalSum % 2 != 0) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  long long target = totalSum / 2;

  vector<long long> set1;
  vector<long long> set2;

  for (long long i = n; i >= 1; i--) {
    if (i <= target) {
      set1.push_back(i);
      target -= i;
    } else {
      set2.push_back(i);
    }
  }

  cout << set1.size() << '\n';
  set1.reserve(set1.size());
  for (long long value : set1) {
    cout << set1.back() << " ";
    set1.pop_back();
  }
  cout << '\n';

  cout << set2.size() << '\n';
  for (long long value : set2) {
    cout << set2.back() << " ";
    set2.pop_back();
  }
  cout << '\n';

  return 0;
}
