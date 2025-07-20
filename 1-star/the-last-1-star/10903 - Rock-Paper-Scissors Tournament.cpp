#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
map<string, string> w = {{"rock", "scissors"}, {"paper", "rock"}, {"scissors", "paper"}};

int who(int p1, string c1, int p2, string c2) {
    if (w[c1] == c2) return p1;
    if (w[c2] == c1) return p2;
    return -1; //tie
}

int main() {
    int n, k;
    bool first = true;
    
    while (cin >> n >> k && n != 0) {
        if (!first) cout << '\n';
        first = false;
        int t = k * n * (n - 1) / 2;
        map<int, pair<int, int>> mp; //player n, win counts, play counts
        map<int, double> win;
        for (int i = 1; i <= t; ++i) {
            int p1, p2;
            string c1, c2;
            cin >> p1 >> c1 >> p2 >> c2;
            int tmp1 = who(p1, c1, p2, c2);
            if (tmp1 != -1) {
                mp[tmp1].first++, mp[tmp1].second++;
                int tmp2 = (tmp1 != p1) ? p1 : p2;
                mp[tmp2].second++;
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (mp[j].second != 0)
                win[j] = mp[j].first / (double)mp[j].second;
            else 
                win[j] = -1.0;
        }
        for (auto &p : win) {
            if (p.second != -1.0)
                cout << fixed << setprecision(3) << p.second << '\n';
            else 
                cout << "-\n"; 
        }
    }
}
