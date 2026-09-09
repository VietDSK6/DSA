#include <bits/stdc++.h>

using namespace std;


void solve(string a, string b) {
    string minA = "", maxA ="";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '6') {
            minA += '5';
            maxA += a[i];
        } else if (a[i] == '5') {
            maxA+= '6';
            minA+= a[i];
        } else {
            
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  string a, b;
  while (tc--) {
    cin >> a >> b;
    solve(a, b);
  }
}
