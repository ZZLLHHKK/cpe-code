#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    bool first = true;
    map<char, char> lose = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    cin >> t;

    while (t--) {
        if (!first) cout << '\n';
        first = false;
        int r, c, ro;
        cin >> r >> c >> ro;
        char board[105][105], tmp[105][105];
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) 
                cin >> board[i][j];
        }
        while (ro--) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (board[i - 1][j] == lose[board[i][j]] && i - 1 >= 0) tmp[i][j] = lose[board[i][j]];
                    else if (board[i + 1][j] == lose[board[i][j]] && i + 1 < r) tmp[i][j] = lose[board[i][j]];
                    else if (board[i][j - 1] == lose[board[i][j]] && j - 1 >= 0) tmp[i][j] = lose[board[i][j]];
                    else if (board[i][j + 1] == lose[board[i][j]] && j + 1 < c) tmp[i][j] = lose[board[i][j]];
                    else tmp[i][j] = board[i][j];
                }
            }
            memcpy(board, tmp, sizeof(board));
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                cout << board[i][j] << (j == c - 1 ? "\n" : "");
        }
    }
}
