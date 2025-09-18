#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll x;

    while ((cin >> x) && !cin.eof()) {
        cin.ignore();
        ll tmp, res = 0;
        vector<ll> n;
        string func;
        getline(cin, func);
        stringstream ss(func);

        while (ss >> tmp) 
            n.push_back(tmp);
        
        int s = (int)n.size() - 1;
        for (int i = 0; i < s; ++i) 
            res = res * x + n[i] * (s - i);
        cout << res << '\n';
    }
}
