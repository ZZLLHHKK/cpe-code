#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int prime(int n) {
    if (n == 0 || n == 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    string n, r;

    while (cin >> n) {
        int p1 = prime(stoi(n)); //prime
        copy(n.rbegin(), n.rend(), r.begin());
        int p2 = prime(stoi(r)); //emirp

        if (p1 == 1 && p2 == 1) {
            if (n == r)
                cout << n << " is prime.\n";
            else 
                cout << n << " is emirp.\n";
        }
        else if (p1 == 0)
            cout << n << " is not prime.\n";
        else if (p1 == 1 && p2 == 0)
            cout << n << " is prime.\n";
    }
}
