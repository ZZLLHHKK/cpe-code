#include <iostream>
#include <algorithm>
using namespace std;

int count(int n, int cnt = 1) {
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        else {
            n = 3 * n + 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int x, y;

    while (cin >> x >> y) {
        int tmpx = x, tmpy = y, ans = 0;
        if (x > y) 
            tmpx = y, tmpy = x;
        for (int i = tmpx; i <= tmpy; ++i) 
            ans = max(ans, count(i));
        cout << x << " " << y << " " << ans << '\n';
    }
}
