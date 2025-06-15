#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;

    while (cin >> a >> b) {
        if (a == "0" && b == "0") break;
        int cnt = 0, mx = max(a.size(), b.size()), carry = 0;
        string zero = "";
        for (int i = 0; i < mx - min(a.size(), b.size()); ++i) zero += "0";
        if (a.size() > b.size()) b = zero + b;
        else a = zero + a;
        for (int j = a.size() - 1; j >= 0; --j) {
            if ((a[j] - '0') + (b[j] - '0') + carry > 9) {
                cnt++;
                carry = 1;
            }
            else carry = 0;
        }
        
        if (cnt > 0) {
            if (cnt == 1)
                cout << "1 carry operation.\n";
            else 
                cout << cnt << " carry operations.\n";
        }
        else 
            cout << "No carry operation.\n";
    }
}
