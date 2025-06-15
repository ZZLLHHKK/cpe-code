#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> fi(50);

void fib(vector<ll> &fi) {
    fi[0] = 0, fi[1] = 1;
    for (int i = 2; i < 50; ++i) 
        fi[i] = fi[i - 1] + fi[i - 2];
}

int main() {
    int t;
    cin >> t;
    fib(fi);

    while (t--) {
        ll n, tmp, flag = 1;
        vector<int> ans;
        cin >> n;
        tmp = n;
        for (int i = 49; i > 0; --i) {
            if (tmp % fi[i] == tmp && flag == 1) continue;
            else flag = 0;
            ans.push_back(tmp / fi[i]);
            tmp %= fi[i];
        }
        cout << n << " = ";
        for (int j = 0; j < ans.size() - 1; ++j)
            cout << ans[j];
        cout << " (fib)\n";
    }   
}
