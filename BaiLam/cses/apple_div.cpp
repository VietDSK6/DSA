#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> weights;
long long totalWeight = 0;
long long minDiff = LLONG_MAX;

void backtrack(int index, long long group1Weight) {
  if (index == n) {
    long long group2Weight = totalWeight - group1Weight;
    long long difference = abs(group1Weight - group2Weight);

    minDiff = min(minDiff, difference);
    return;
  }

  backtrack(index + 1, group1Weight + weights[index]);

  backtrack(index + 1, group1Weight);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  weights.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
    totalWeight += weights[i];
  }

  backtrack(0, 0);

  cout << minDiff << '\n';

  return 0;
}
