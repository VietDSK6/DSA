#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<long long, vector<long long>, greater<long long>> pq;

  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    pq.push(x);
  }

  long long totalCost = 0;

  while (pq.size() > 1) {
    long long a = pq.top();
    pq.pop();

    long long b = pq.top();
    pq.pop();

    long long cost = a + b;
    totalCost += cost;

    pq.push(cost);
  }

  cout << totalCost << '\n';

  return 0;
}
