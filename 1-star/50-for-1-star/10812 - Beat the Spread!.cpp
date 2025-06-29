#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        double a, b, x, y;
        cin >> a >> b;
        x = (a + b) / 2, y = (a - b) / 2;
        if (a < b || (x - (long long)x) != 0 || (y - (long long)y != 0)) {
            cout << "impossible" << '\n';
            continue;
        }
        cout << fixed << setprecision(0) << x << " " << fixed << setprecision(0) << y << '\n';
    }
}
