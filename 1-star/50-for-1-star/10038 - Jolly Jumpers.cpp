#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int t;

    while (cin >> t) {
        int n[t + 1] = {}, d[t + 1] = {}, flag = 1;
        for (int i = 0; i < t; ++i)
            cin >> n[i];
        for (int j = 0; j < t - 1; ++j)
            d[j] = abs(n[j] - n[j + 1]);
        sort(d, d + t, cmp);
        for (int k = 0; k < t - 1; ++k) {
            if (d[k] - d[k + 1] != 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << "Jolly\n";
        else 
            cout << "Not jolly\n";
    }
}
