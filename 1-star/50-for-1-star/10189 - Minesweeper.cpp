#include <iostream>
#include <string.h>
using namespace std;
char b[102][102];

int count(int i, int j) {
    int cnt = 0;
    for (int r = i - 1; r <= i + 1; ++r) {
        for (int c = j - 1; c <= j + 1; ++c) 
            if (b[r][c] == '*') cnt++;
    }
    return cnt;
}

int main() {
    int m, n, t = 1;
    bool first = true;

    while (cin >> m >> n && (m != 0 && n != 0)) {
        if (!first)
            cout << '\n';
        first = false;
        memset(b, '.', sizeof(b));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) 
                cin >> b[i][j];
        }
        cout << "Field #" << t++ << ":\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j] == '*') cout << '*';
                else cout << count(i, j);
            }
            cout << '\n';
        }
    }
}
