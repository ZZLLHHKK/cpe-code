#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    while (cin >> n) {
        int res = -INT_MAX, subRec;
        int m[101][101];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
                if (i > 0) m[i][j] += m[i - 1][j];
                if (j > 0) m[i][j] += m[i][j - 1];
                if (i > 0 && j > 0) m[i][j] -= m[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int x = i; x < n; ++x) {
                    for (int y = j; y < n; ++y) {
                        subRec = m[x][y];
                        if (i > 0) subRec -= m[i - 1][y];
                        if (j > 0) subRec -= m[x][j - 1];
                        if (i > 0 && j > 0) subRec += m[i - 1][j - 1];
                        res = max(res, subRec);
                    }
                }
            }
        }
        cout << res << '\n';
    }
}
