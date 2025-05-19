#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int cnt = 1;

int main() {
    string s;

    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '"') {
                if (cnt % 2 == 1) cout << "``";
                else cout << "''";
                cnt++;
            }
            else 
                cout << s[i];
        }
        cout << '\n';
    }
}
