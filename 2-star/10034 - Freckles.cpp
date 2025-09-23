#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>

struct edge {
    double dis;
    pdd u, v;
    edge(pdd _u, pdd _v) : u(_u), v(_v) { dis = sqrt(pow(u.first - v.first, 2) + pow(u.second - v.second, 2)); }
    bool operator<(const edge &other) const { return dis > other.dis; }
};

int main() {
    int t;
    bool first = true;
    cin >> t;
    string line;
    getline(cin, line); 
    
    while (t--) {
        if (!first) cout << "\n\n";
        first = false;
        int n;
        double ans = 0;
        cin >> n;
        map<pdd, bool> vis;
        map<pdd, vector<edge>> connect;
        vector<pdd> pt(n);
        priority_queue<edge, vector<edge>> pq;
        for (int i = 0; i < n; ++i)  {//input the point
            cin >> pt[i].first >> pt[i].second;
            vis[pt[i]] = false;
        }
        for (int i = 0; i < n - 1; ++i) { //create edge
            for (int j = i + 1; j < n; ++j) { 
                connect[pt[i]].push_back(edge(pt[i], pt[j]));
                connect[pt[j]].push_back(edge(pt[j], pt[i]));
            }
        }
        int cnt = 0, num = n - 1;
        for (auto e : connect[pt[0]])
            pq.push(e);

        while (!pq.empty() && cnt < num) {
            edge e = pq.top();
            pq.pop();
            pdd v = e.v; 
            if (vis[v]) continue; 
            cnt++;
            ans += e.dis;
            vis[e.u] = vis[v] = true;
            for (auto s : connect[v]) 
                if (!vis[s.v]) pq.push(s); 
        }
        cout << fixed << setprecision(2) << ans;
    }
    cout << '\n';
}
