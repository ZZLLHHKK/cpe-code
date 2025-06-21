#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

ll convert(string n) {
    ll ans = 0;
    for (int i = n.size() - 1, j = 0; i >= 0 && j < n.size(); --i, ++j) 
        ans += (n[j] -'0') * pow(2, i);
    return ans;
}   

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        string a, b;
        cin >> a >> b;
        ll f = __gcd(convert(a), convert(b));
        cout << "Pair #" << i << ": ";
        if (f == 1)
            cout << "Love is not all you need!\n";
        else 
            cout << "All you need is love!\n";
    }
}
