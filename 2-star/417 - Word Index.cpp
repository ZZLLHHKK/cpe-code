#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

void bfs() {
    int cnt = 1;
    queue<string> q;

    for (char c = 'a'; c <= 'z'; ++c) {
        string s(1, c);
        q.push(s);
        mp[s] = cnt++;
    }

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        if (cur.size() == 5) continue;

        for (char c = cur.back() + 1; c <= 'z'; ++c) {
            string next = cur + c;
            q.push(next);
            mp[next] = cnt++;
        }
    }
}

int main() {
    string n;
    bfs();

    while (getline(cin, n)) 
        cout << (mp.find(n) == mp.end() ? 0 : mp[n]) << '\n';
}
