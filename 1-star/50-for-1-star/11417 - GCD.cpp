#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    int N;
    
    while (cin >> N && N != 0) {
        ll G = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = i + 1; j <= N; ++j)
                G += __gcd(i,j);
        }
        cout << G << '\n';
    }
}
