#include <bits/stdc++.h>
using namespace std;

struct Request {
  int start;
  int finish;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Request> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].start >> a[i].finish;
  }

  // Sắp xếp theo thời điểm kết thúc
  sort(a.begin(), a.end(),
       [](const Request &x, const Request &y) { return x.finish < y.finish; });

  // endTime[i] = thời điểm kết thúc của yêu cầu thứ i
  vector<int> endTime(n);

  for (int i = 0; i < n; i++) {
    endTime[i] = a[i].finish;
  }

  // dp[i] = đáp án tốt nhất với i yêu cầu đầu tiên
  vector<long long> dp(n + 1, 0);

  for (int i = 1; i <= n; i++) {

    int start = a[i - 1].start;
    int finish = a[i - 1].finish;

    long long duration = finish - start;

    // Tìm số lượng yêu cầu có thời điểm kết thúc <= start
    int j = upper_bound(endTime.begin(),  endTime.begin() + (i - 1), start) -
            endTime.begin();

    // Không chọn i hoặc chọn i
    dp[i] = max(dp[i - 1], dp[j] + duration);
  }

  cout << dp[n] << '\n';

  return 0;
}
