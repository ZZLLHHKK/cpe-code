#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        int tmp = 0;
        bool f;
        string str, n;
        set<int> s;
        cin >> str;
        n = str;
        while (tmp != 1 && tmp != stoi(n)) {
            for (int j = 0; j < n.size(); ++j)
                tmp += (n[j] - '0') * (n[j] - '0');
            if (s.find(tmp) == s.end()) {
                s.insert(tmp);
                n = to_string(tmp);
                tmp = 0;
            }
            else {
                f = false;
                break;
            }
        }
        if (tmp == 1) f = true;
        else f = false;
        cout << "Case #" << i << ": " << str << " is " << (f ? "a Happy " : "an Unhappy ") << "number.\n";
    }
}
