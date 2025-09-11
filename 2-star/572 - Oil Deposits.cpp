#include <iostream>
#include <string.h>
using namespace std;

int cnt = 0, r, c;
int vis[100][100] = {};
char b[101][101];

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= r || j >= c || b[i][j] == '*' || vis[i][j] == 1) return;
    vis[i][j] = 1;
    for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
            if (a == 0 && b == 0) continue;
            dfs(i - a, j - b);
        }
    }
}

int main() {

    while (cin >> r >> c && r != 0 && c != 0) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                cin >> b[i][j];
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (vis[i][j] != 1 && b[i][j] == '@') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';;
        cnt = 0;
    }
}
