#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int tar, s;
        cin >> tar >> s;
        vector<int> l(s);
        for (int i = 0; i < s; ++i) 
            cin >> l[i];
        if (tar == 0) {
            cout << "YES\n";
            continue;
        }
        vector<bool> dp(tar + 1, false);
        dp[0] = true;
        for (int i = 0; i < s; ++i) {
            for (int j = tar; j >= l[i]; --j) {
                if (dp[j - l[i]]) 
                    dp[j] = true;
            } 
        }
        cout << (dp[tar] == true ? "YES\n" : "NO\n");
    }
}
