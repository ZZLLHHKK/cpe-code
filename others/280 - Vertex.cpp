#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u) {
    for (int v = 0; v < adj.size(); ++v) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            dfs(adj, vis, v);
        }
    }
}

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        while (1) { //create graph
            int init, goal;
            cin >> init;
            if (init == 0) break;
            while (cin >> goal && goal != 0) 
                adj[init - 1][goal - 1] = 1;
        }
        int t, search;
        cin >> t; //search vertex reach ability
        while (t--) {
            vector<int> res;
            vector<bool> vis(n, false);
            cin >> search;
            dfs(adj, vis, search - 1);
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) 
                    res.push_back(i + 1);
            }
            cout << res.size();
            for (int x : res) cout << " " << x;
            cout << "\n";
        }
    }
}
