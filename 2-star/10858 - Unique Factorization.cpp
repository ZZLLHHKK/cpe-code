#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(4000010, true);

void seive() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 2000000; ++i) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 2000000; j += i)
                prime[j] = false;
        }
    }
}

void dfs(int n, int start, vector<int> &tmp, set<vector<int>> &res) {
    if (n == 1 && tmp.size() > 1) {
        res.insert(tmp);
        return;
    }
    for (int i = start; i <= n; ++i) {
        if (n % i == 0) {
            tmp.push_back(i);
            dfs(n / i, i, tmp, res);  
            tmp.pop_back();
        }
    }
}

int main() {
    int n;
    seive();

    while (cin >> n && n != 0) {
        if (prime[n] || n == 1) {
            cout << "0\n";
            continue;
        }
        vector<int> tmp;
        set<vector<int>> res;
        dfs(n, 2, tmp, res);
        cout << res.size() << '\n';
        for (auto &p : res) {
            for (int i = 0; i < p.size(); ++i) 
                cout << p[i] << (i != p.size() - 1 ? " " : "\n");
        }
    }
}
