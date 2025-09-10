#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &f, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if ((f[i] == col) || abs(f[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(vector<vector<int>> &b, vector<int> &f, int row, int *mx) { //(i, f[i]) = (row, col)
    if (row == 8) {
        int tmp = 0;
        for (int i = 0; i < f.size(); ++i) 
            tmp += b[i][f[i]];
        *mx = max(*mx, tmp);
        return;
    }
    for (int col = 0; col < 8; ++col) {
        if (isSafe(f, row, col)) {
            f[row] = col;
            solve(b, f, row + 1, mx);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int mx = -INT_MAX;
        vector<int> f(8, -1);
        vector<vector<int>> b(8, vector<int>(8, 0)); //board
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j)
                cin >> b[i][j];
        }
        solve(b, f, 0, &mx);
        cout << setw(5) << mx << '\n';
    }
}
