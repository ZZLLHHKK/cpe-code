#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find(vector<int> &arr, int n) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == n)
            return 1;
    }
    return 0;
}

int main() {
    int t; 
    string cmd[1000];
    cin >> t;
    map<char, vector<int>> m = {{'c', {2, 3, 4, 7, 8, 9, 10}}, {'d', {2, 3, 4, 7, 8, 9}}, {'e', {2, 3, 4, 7, 8}},
                                {'f', {2, 3, 4, 7}}, {'g', {2, 3, 4}}, {'a', {2, 3}}, {'b', {2}},
                                {'C', {3}}, {'D', {1, 2, 3, 4, 7, 8, 9}}, {'E', {1, 2, 3, 4, 7, 8}},
                                {'F', {1, 2, 3, 4, 7}}, {'G', {1, 2, 3, 4}}, {'A', {1, 2, 3}}, {'B', {1, 2}}};
    cin.ignore(); //be careful, when you press enter, the test case will be seen as a count, it will cover your input
    for (int i = 0; i < t; ++i) 
        getline(cin, cmd[i]);

    for (int x = 0; x < t; ++x) {
        int cnt[10] = {}, used[10]= {};
        
        for (int i = 0; i < cmd[x].size(); ++i) {
            for (int k = 0; k < m[cmd[x][i]].size(); ++k) {
                int tmp = m[cmd[x][i]][k];
                for (int r = 0; r < 10; ++r) {
                    if (used[r] == 1 && find(m[cmd[x][i]], r + 1) == 0) //目前有用 但等等不用
                        used[r] = 0;
                }
            }
            for (int j = 0; j < m[cmd[x][i]].size(); ++j) {
                int tmp = m[cmd[x][i]][j];
                if (used[tmp - 1] != 1) { 
                    cnt[tmp - 1]++;
                    used[tmp - 1] = 1;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            cout << cnt[i];
            if (i != 9)
                cout << " ";
        }
        cout << '\n';
    }
}
