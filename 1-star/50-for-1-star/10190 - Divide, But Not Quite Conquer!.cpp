#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ll n, m;

    while (cin >> n >> m) {
        if (m == 0 || n == 0 || m == 1 || n == 1 || (n < m)) {
            cout << "Boring!\n";
            continue;
        }
        int f = 1;
        vector<ll> num;
        num.push_back(n);
        
        while (n != 1) {
            if (n % m == 0) {
                num.push_back(n / m);
                n /= m;
            }
            else {
                f = 0;
                cout << "Boring!\n";
                break;
            }
        }
        if (!f) continue;

        for (int i = 0; i < num.size(); ++i) {
            cout << num[i];
            if (i != num.size() - 1) cout << " ";
        }
        cout << '\n';
    }
}
