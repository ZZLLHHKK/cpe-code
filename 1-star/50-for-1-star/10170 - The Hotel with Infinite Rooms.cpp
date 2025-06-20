#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll s, d;
    
    while (cin >> s >> d) {
        ll tmp = 0, dif = 0;
        for (ll i = s; tmp < d; ++i) {
            tmp += i;
            dif++;
        }
        cout << s + dif - 1 << '\n';
    }
}
