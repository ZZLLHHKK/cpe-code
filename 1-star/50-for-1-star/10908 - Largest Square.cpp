#include <iostream>
#include <string.h>
using namespace std;

char b[101][101];

int check(int i, int j) {
    int cnt = 0, range = 1;
    char tar = b[i][j];
    while (1) {
        for (int r = i - range; r <= i + range; ++r) {
            for (int c = j - range; c <= j + range; ++c) {
                if (tar != b[r][c]) 
                    return cnt;
            }
        }
        cnt++, range++;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c, q, x, y;
        cin >> r >> c >> q;
        memset(b, ' ', sizeof(b));
        for (int i = 0; i < r; ++i) 
            cin >> b[i];
        cout << r << " " << c << " " << q << '\n';
        for (int j = 0; j < q; ++j) {
            cin >> x >> y;
            cout << 2 * check(x, y) + 1 << '\n';
        }
    }
}
