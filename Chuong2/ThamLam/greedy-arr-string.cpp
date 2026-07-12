#include <bits/stdc++.h>
using namespace std;

struct Node {
  char ch;
  int freq;
};

void solve() {
  string s;
  int d;
  cin >> s >> d;

  int n = s.size();

  map<char, int> mp;

  // Bước 1: Đếm số lần xuất hiện mỗi ký tự
  for (char c : s) {
    mp[c]++;
  }

  vector<Node> a;

  for (auto x : mp) {
    a.push_back({x.first, x.second});
  }

  // Bước 2: Sắp xếp giảm dần theo số lần xuất hiện
  sort(a.begin(), a.end(), [](Node x, Node y) { return x.freq > y.freq; });

  string res(n, '#');

  // Bước 3: Điền ký tự
  for (int i = 0; i < (int)a.size(); i++) {
    char c = a[i].ch;
    int p = a[i].freq;

    for (int t = 0; t < p; t++) {
      int pos = i + t * d;

      if (pos >= n) {
        cout << "Vo nghiem\n";
        return;
      }

      if (res[pos] != '#') {
        cout << "Vo nghiem\n";
        return;
      }

      res[pos] = c;
    }
  }

  // Nếu còn vị trí chưa được điền thì vô nghiệm
  for (char c : res) {
    if (c == '#') {
      cout << "Vo nghiem\n";
      return;
    }
  }

  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
