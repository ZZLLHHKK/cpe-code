#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<string>> res;
void solve() {
    for (int i = 2; i <= 8; i += 2) {
        int half = i / 2;
        for (int j = 0; j <= 9999; ++j) {
            int x = j * j;
            string str = to_string(x);

            while (str.size() < i) str = '0' + str;
            if (str.size() > i) continue;

            int l = stoi(str.substr(0, half)), r = stoi(str.substr(half));
            if ((l + r) * (l + r) == x)
                res[i].push_back(str);
        }
    }
}

int main() {
    int n;
    solve();

    while (cin >> n) {
        for (auto &str : res[n])
            cout << str << '\n';
    }
}
