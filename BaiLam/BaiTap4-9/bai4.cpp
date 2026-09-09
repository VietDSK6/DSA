#include <bits/stdc++.h>
using namespace std;

struct Activity {
  int id;
  int start;
  int finish;
};

bool cmp(const Activity &a, const Activity &b) { return a.finish < b.finish; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<Activity> a(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i].start;
      a[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
      cin >> a[i].finish;
    }

    sort(a.begin(), a.end(), cmp);

    vector<Activity> opt;
    if (n > 0) {
      opt.push_back(a[0]);
      int lastFinish = a[0].finish;
      for (int j = 1; j < n; j++) {
        if (a[j].start >= lastFinish) {
          opt.push_back(a[j]);
          lastFinish = a[j].finish;
        }
      }
    }
    cout << opt.size() << "\n";
  }
  return 0;
}
