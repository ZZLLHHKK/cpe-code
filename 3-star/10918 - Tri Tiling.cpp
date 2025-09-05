#include <bits/stdc++.h>
using namespace std;

vector<int64_t> dp(31, 0);
void solve() {
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 3; i <= 30; ++i) {
        if (i % 2)
            dp[i] = 0;
        else 
            dp[i] = (4 * dp[i - 2]) - dp[i - 4];
    }
}

int main() {
    int t;
    solve();

    while (cin >> t && t != -1) 
        cout << dp[t] << '\n';
}
