#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(2000001, true);

void seive() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 1000000; ++i) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) 
                prime[j] = false;
        }
    }
}

void solve(int n) {
    int a = 0, b = 0, dif = 0;
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            a = i;
            if (prime[n - i]) {
                b = n - i;
                dif = b - a;
                cout << n << " = " << a << " + " << b << '\n';
                break;
            }
        }
    }
    if (a == 0 || b == 0)
        cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    int n;
    seive();

    while (cin >> n && n != 0) 
        solve(n);
}
