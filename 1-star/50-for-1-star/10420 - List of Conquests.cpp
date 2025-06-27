#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    int t;

    while (cin >> t) {
        int flag = 1;
        t++;
        string s, tmp;
        map<string, int> p;
        for (int i = 0; i < t; ++i) {
            getline(cin, s);
            stringstream ss(s);
            while (ss >> tmp && flag == 1) {
                p[tmp]++;
                flag = 0;
            }
            flag = 1;
        }
        for (auto &name : p)
            cout << name.first << " " << name.second << '\n';
    }
}
