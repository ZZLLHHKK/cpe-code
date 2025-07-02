#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

bool cmp(int a, int b) {
    if (a % m != b % m) //a front b back
        return a % m < b % m;
    if (a % 2) { //a is odd
        if (b % 2) // b is odd
            return a > b;
        return true; // b is even
    }
    if (b % 2) // a even b odd
        return false;
    return a < b; //a and b are even
}

int main() {
    while (cin >> n >> m) {
        cout << n << " " << m << '\n';
        if (n == 0 && m == 0) break;
        int ar[20001] = {};
        for (int i = 0; i < n; ++i) 
            cin >> ar[i];
        sort(ar, ar + n, cmp);
        for (int j = 0; j < n; ++j) 
            cout << ar[j] << '\n';
    }
}
