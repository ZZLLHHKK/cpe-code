#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int mx = 0;
    string a;
    vector<string> s;

    while (getline(cin, a)) {
        s.push_back(a);
        mx = max((int)a.length(), mx);
    }
    reverse(s.begin(), s.end());

    int j = 0;
    while (1) {
        for (string &str : s) {
            if (j < str.length())
                cout << str[j];
            else 
                cout << " ";
        }
        cout << '\n';
        j++;
        if (j >= mx) break;
    }
}
