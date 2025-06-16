#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int pl, i; //player, i-th
        double p; //probability
        cin >> pl >> p >> i;
        if (p == 0.0000) {
            cout << "0.0000\n";
            continue;
        }
        double fail = 1 - p;
        cout << fixed << setprecision(4) << p * (pow(fail, i - 1) / (1 - pow(fail, pl))) << '\n';
    }
}
