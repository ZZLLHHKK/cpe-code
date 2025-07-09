#include <iostream>
#include <vector>
using namespace std;

struct state {
    vector<vector<int>> dup;

    bool operator==(const state &other) {
        return dup == other.dup;
    }
};

vector<vector<int>> rotateRight(vector<vector<int>> b, int n) { //rotate 90 degree
    vector<vector<int>> ans(n, vector<int>(n, 0)), tmp(n, vector<int>(n, 0));
    for (int i = 0, k = n - 1; i < n && k >= 0; ++i, --k) 
        for (int j = 0; j < n; ++j) tmp[i][j] = b[k][j];
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) ans[j][i] = tmp[i][j];

    return ans;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        int x, y, flag = 0, win = 0, step = 0;
        char c;
        vector<vector<int>> b(n, vector<int>(n, 0));
        vector<state> check;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> x >> y >> c;
            if (flag) continue;
            if (c == '+')
                b[y - 1][x - 1] = 1;
            else 
                b[y - 1][x - 1] = 0;
            state cmp = {b};
            for (int j = 0; j < 4; ++j) { //90, 180, 270, 360
                b = rotateRight(b, n);
                if (cmp.dup != b) 
                    check.push_back({b});
            }
            if (i > 0) {
                for (int k = 0; k < check.size(); ++k) {
                    if (cmp == check[k]) { //the same previous pattern
                        step = i + 1;
                        win = (i % 2) ? 1 : 2;
                        flag = 1;
                        break;
                    }
                }
            }
            check.push_back({b});
        }
        if (flag) 
            cout << "Player " << win << " wins on move " << step << '\n';
        else 
            cout << "Draw\n";
    }
}
