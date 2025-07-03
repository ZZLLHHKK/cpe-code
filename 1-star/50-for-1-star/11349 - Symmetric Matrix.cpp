#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        char ch, eq;
        long long s, m[20001] = {}, flag = 1;
        cin >> ch >> eq >> s;
        for (int j = 0; j < s * s; ++j) 
            cin >> m[j];
        for (int l = 0, r = (s * s) - 1; l < (s * s) && r >= 0; ++l, --r) {
            if (m[l] != m[r] || m[l] < 0 || m[r] < 0) {
                flag = 0; 
                break;
            }
        }
        if (flag)
            cout << "Test #" << i << ": Symmetric.\n";
        else 
            cout << "Test #" << i << ": Non-symmetric.\n";
    }
}
