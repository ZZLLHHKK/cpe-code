#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int a, b, sum = 0;
        cin >> a >> b;
        if (a > b) swap(a, b);
        for (int j = a; j <= b; ++j)
            sum += (j % 2) ? j : 0;
        cout << "Case " << i << ": " << sum << '\n';
    }
}
