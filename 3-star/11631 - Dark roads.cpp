#include <bits/stdc++.h>
using namespace std;
vector<int> p;

int find(int x) {
    return (p[x] < 0 ? x : p[x] = find(p[x]));
}

bool Union(int x, int y) {
    int g1 = find(x), g2 = find(y);
    if (g1 == g2) return false; 
    if (p[g1] > p[g2]) swap(g1, g2); 
    p[g1] += p[g2];
    p[g2] = g1;
    return true; 
}

struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};  
};

bool cmp(edge a, edge b) { return a.w < b.w; }

int main() {
    int n, e;

    while (cin >> n >> e && (n != 0 && e != 0)) {
        int res = 0, cnt = 0, total = 0, uu, vv, ww;
        vector<edge> ed;
        for (int i = 0; i < e; ++i) {
            cin >> uu >> vv >> ww;
            total += ww;
            ed.push_back(edge(uu, vv, ww));
        }
        sort(ed.begin(), ed.end(), cmp);
        p.assign(n + 1, -1);
        for (int i = 0; i < e; ++i) {
            if (Union(ed[i].u, ed[i].v) && cnt < n - 1) {
                res += ed[i].w;
                cnt++;
            }
        }
        cout << total - res << '\n';
    }
}
