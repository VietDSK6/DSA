#include <bits/stdc++.h>
using namespace std;

struct Activity {
  int id;
  int start;
  int finish;
};

bool cmp(Activity a, Activity b) { return a.finish < b.finish; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Activity> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].start >> a[i].finish;
    a[i].id = i + 1; // lưu lại số thứ tự ban đầu
  }

  // Bước 1: Sắp xếp theo thời gian kết thúc tăng dần
  sort(a.begin(), a.end(), cmp);

  vector<Activity> opt;

  // Bước 2: Chọn hoạt động đầu tiên
  if (n > 0) {
    opt.push_back(a[0]);
    int lastFinish = a[0].finish;

    // Bước 3: Duyệt các hoạt động còn lại
    for (int j = 1; j < n; j++) {
      if (a[j].start >= lastFinish) {
        opt.push_back(a[j]);
        lastFinish = a[j].finish;
      }
    }
  }

  // Bước 4: Trả lại kết quả
  cout << "So hoat dong duoc chon: " << opt.size() << '\n';
  cout << "Cac hoat dong duoc chon:\n";

  for (Activity x : opt) {
    cout << "Hoat dong " << x.id << ": start = " << x.start
         << ", finish = " << x.finish << '\n';
  }

  return 0;
}
