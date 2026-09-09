#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
      int n, S;
      cin >> n >> S;
    
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
    
      vector<bool> dp(S + 1, false);
      dp[0] = true;
    
      for (int i = 0; i < n; i++) {
        for (int j = S; j >= a[i]; j--) {
          dp[j] = dp[j] || dp[j - a[i]];
        }
      }
    
      cout << (dp[S] ? "YES" : "NO");
      cout << "\n";
  }
 

  return 0;
}
