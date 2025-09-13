#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u) {
    for (int v = 0; v < adj[u].size(); ++v) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            dfs(adj, vis, v);
        }
    }
}

int main() {
    int t;
    string line, blank;
    cin >> t;
    getline(cin, blank);

    for (int i = 1; i <= t; ++i) {
        char num;
        cin >> num;
        getline(cin, blank);
        int cnt = 0, mx = (num - 'A') + 1;
        vector<bool> vis(mx, false);
        vector<vector<int>> adj(mx, vector<int>(mx, 0));

        while (getline(cin, line) && !line.empty()) {
            if (adj[line[0] - 'A'][line[0] - 'A'] == 1) adj[line[0] - 'A'][line[0] - 'A'] = 0; //closed cycle
            if (adj[line[1] - 'A'][line[1] - 'A'] == 1) adj[line[1] - 'A'][line[1] - 'A'] = 0;
            adj[line[1] - 'A'][line[0] - 'A'] = 1;
            adj[line[0] - 'A'][line[1] - 'A'] = 1;
        }

        for (int j = 0; j < mx; ++j) {
            if (!vis[j]) {
                dfs(adj, vis, j);
                cnt++;
            }
        }
        cout << cnt << "\n";
        if (i != t) cout << '\n';
    }
}
