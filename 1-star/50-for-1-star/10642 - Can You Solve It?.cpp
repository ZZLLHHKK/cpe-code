#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int a, b, c, d, cnt = 0;
        cin >> a >> b >> c >> d;
        if (a + b > c + d || ((a + b == c + d) && (a > c || b < d))) {
            swap(a, c);
            swap(b, d);
        }
        int tmp1 = a, tmp2 = b, tmp3 = c, tmp4 = d;
        if (a + b != c + d) {
            while (tmp1 != a + b && tmp2 != 0) //upword
                tmp1++, tmp2--, cnt++;
            while (tmp3 != 0 && tmp4 != c + d) //downward
                tmp3--, tmp4++, cnt++;
            for (int i = (a + b) + 1; i <= (c + d) - 1; ++i)
                cnt += (i + 1);
            cnt++;
        }
        else {
            while (tmp3 != tmp1)
                tmp3--, cnt++;
        }
        cout << "Case " << i << ": " << cnt << '\n';
    }
}
