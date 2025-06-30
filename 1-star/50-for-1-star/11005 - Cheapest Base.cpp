#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#define pii pair<int, int>
const string b = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool cmp(pii a, pii b) {
    if (a.second != b.second) return a.second < b.second;
    if (a.second == b.second) return a.first < b.first;
}

int main() {
    int t;
    bool first = true;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        if (!first) cout << '\n';
        first = false;
        int cost, sample, num;
        vector<pii> ans;
        map<char, int> table;
        for (int j = 0; j < 36; ++j) {
            cin >> cost;
            table[b[j]] = cost;
        }
        cout << "Case " << i << ":\n";
        cin >> sample;
        for (int k = 0; k < sample; ++k) {
            cin >> num;
            cout << "Cheapest base(s) for number " << num << ": ";
            for (int x = 2; x <= 36; ++x) {
                int sum = 0, tmp = num;
                vector<int> res;
                while (tmp > 0) {
                    res.push_back(tmp % x);
                    tmp /= x;
                }
                for (int v : res) 
                    sum += table[b[v]];
                ans.push_back(make_pair(x, sum));
            }
            sort(ans.begin(), ans.end(), cmp);
            int det = ans[0].second, cnt = 1;
            for (int w = 1; w < ans.size(); ++w) 
                if (ans[w].second == det) cnt++;
            for (int y = 0; y < cnt; ++y) {
                cout << ans[y].first;
                if (y != cnt - 1) cout << " ";
            }
            cout << '\n';
            ans.clear();
        }
    }
}
