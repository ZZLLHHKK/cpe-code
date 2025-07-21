#include <iostream>
using namespace std;
const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int y, int m, int d) {
    int cnt = 0;
    cnt += (y - 1) * 365;
    for (int i = 0; i < m - 1; ++i)
        cnt += month[i];
    cnt += d;
    if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && m > 2) cnt++;
    return cnt;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        int d1, d2, m1, m2, y1, y2, ans;
        char c, b[20], p[20];
        scanf("%s", p); //current
        scanf("%s", b); //born
        sscanf(p, "%d%c%d%c%d", &d1, &c, &m1, &c, &y1); //current
        sscanf(b, "%d%c%d%c%d", &d2, &c, &m2, &c, &y2); //born
        int cur = days(y1, m1, d1), born = days(y2, m2, d2);
        cout << "Case #" << i << ": ";
        if (cur < born)
            cout << "Invalid birth date\n";
        else {
            ans = (cur - born) / 365;
            if (ans > 130)
                cout << "Check birth date\n";
            else 
                cout << ans << '\n';
        }
    }
}
