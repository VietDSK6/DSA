// Cho số tự nhiên N (N≤100). Hãy liệ kê tất cả các cách
// chia số tự nhiên N thành tổng của các số tự nhiên nhỏ hơn N.
// Các cách chia là hoán vị của nhau chỉ được tính là một cách.
// Ví dụ với N= 5 ta có 7 cách chia
// 
#include <bits/stdc++.h>

using namespace std;

int n, dem = 0;
vector<int> a;

void result() {
    cout << ++dem << ": ";
    for (int i = 0; i < a.size(); i++) {
        if (i > 0) cout << " + ";
        cout << a[i];
    }
    cout << "\n";
}

void Try(int remain, int last) {
    if (remain == 0) {
        result();
    }

    for (int i = min(remain, last); i >= 1; i--) {
        a.push_back(i);
        Try(remain-i, i);
        a.pop_back();
    }
}

int main() {
    cin >> n;
    Try(n, n-1);
    return 0;
}