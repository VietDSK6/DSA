#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int F[100][100], n, m, v;
    cin >> n;
    for (int j = 0; j <= n; j++) {
        F[0][j] = 0;
    }
    F[0][0] =1;
    for (m = 1; m <= n; m++) {
        for ( v = 0; v <= n; v++) {
            if (m > v) F[m][v] = F[m-1][v];
            else {
                F[m][v] = F[m-1][v] + F[m][v-m];
            }
        }
    }
    cout << F[n][n];
}