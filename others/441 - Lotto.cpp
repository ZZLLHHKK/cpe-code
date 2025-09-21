#include <bits/stdc++.h>
using namespace std;
set<vector<int>> st;

void dfs(int i, int cnt, vector<int> &s, vector<int> &res) {
    if (cnt == 6) {
        st.insert(res);
        return;
    }
    for (int j = i; j < s.size(); ++j) {
        res.push_back(s[j]);
        dfs(j + 1, cnt + 1, s, res);
        res.pop_back();
    }
}

int main() {
    int n;
    bool first = true;

    while (cin >> n && n != 0) {
        if (!first) cout << '\n';
        first = false;
        vector<int> s(n), res;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        dfs(0, 0, s, res);
        for (auto p : st) {
            for (int k = 0; k < p.size(); ++k) 
                cout << p[k] << (k != p.size() - 1 ? " " : "\n");
        }
        st.clear();
    }
}
