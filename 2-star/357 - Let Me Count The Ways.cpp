#include <iostream>
#include <string.h>
using namespace std;

int64_t dp[30001];
int coin[5] = {1, 5, 10, 25, 50};
void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = coin[i]; j <= 30000; ++j) 
            dp[j] += dp[j - coin[i]];
    }
}

int main() {
    int n;
    solve();

    while (cin >> n) {
        if (dp[n] > 1)
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
        else 
            cout << "There is only " << dp[n] << " way to produce " << n << " cents change.\n";
    }
}
