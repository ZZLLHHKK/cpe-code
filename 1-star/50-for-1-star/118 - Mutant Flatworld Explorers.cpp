#include <iostream>
#include <string.h>
#include <map>
#include <utility>
using namespace std;
map<char, pair<int, int>> di = {{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}}; //N, S, E, W (y, x)
map<char, char> l = {{'N', 'W'}, {'S', 'E'}, {'E', 'N'}, {'W', 'S'}}; //left
map<char, char> r = {{'N', 'E'}, {'S', 'W'}, {'E', 'S'}, {'W', 'N'}}; //right

int main() {
    int m, n, X, Y;
    char dir;
    cin >> m >> n;
    int maze[n + 1][m + 1];
    memset(maze, 0, sizeof(maze));

    while (cin >> X >> Y >> dir) {
        int curX = X, curY = n - Y, flag = 0;
        char d = dir;
        string cmd;
        cin >> cmd;

        for (int i = 0; i < cmd.size(); ++i) {
            if (cmd[i] == 'L') d = l[d];
            if (cmd[i] == 'R') d = r[d];
            if (cmd[i] == 'F') {
                int nextX = curX + di[d].second;
                int nextY = curY + di[d].first;
                if (nextX > m || nextX < 0 || nextY > n || nextY < 0) {
                    if (maze[curY][curX] == 1) continue;
                    else {
                        maze[curY][curX] = 1;
                        flag = 1;
                        break;
                    }
                } 
                else {
                    curX = nextX;
                    curY = nextY;
                }
            }
        }

        cout << curX << " " << n - curY << " " << d;
        if (flag == 1) cout << " LOST\n";
        else cout << '\n';
    }
}
