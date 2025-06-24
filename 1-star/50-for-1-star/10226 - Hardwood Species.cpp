#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

struct p {
    int cnt = 0;
    double r;
};

int main() {
    int t;
    cin >> t;
    bool first = true;

    while (t--) {
        if (!first)
            cout << '\n';
        first = false;

        int total = 0;
        string s;
        map<string, p> spe;

        while (getline(cin, s)) {
            if (s.empty() && total == 0) continue;
            if (s.empty() && total != 0) break;
            spe[s].cnt++, total++;
        }
    
        for (auto s : spe) {
            s.second.r = s.second.cnt / (double)total;
            cout << s.first << " " << fixed << setprecision(4) << s.second.r * 100.0 << '\n';
        }
    }
}
