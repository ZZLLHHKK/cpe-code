#include <iostream>
using namespace std;

int main() {
    int n = 1, t;
    bool first = true;

    while (cin >> t) {
        if (!first) cout << '\n';
        first = false;
        int flag = 1, mx = -0x3f3f3f3f, num[100000], cnt[100000] = {};
        for (int i = 0; i < t; ++i) {
            cin >> num[i];
            if (num[i] <= mx) flag = 0;
            if (num[i] <= 0) flag = 0;
            mx = num[i];
        }
        for (int j = 0; j < t - 1; ++j) {
            for (int k = j; k < t; ++k) 
                cnt[num[j] + num[k]]++;
        }
        for (int k = 0; k < 20000; ++k) {
            if (cnt[k] > 1) {
                flag = 0;
                break;
            }
        }
        if (flag) 
            cout << "Case #" << n++ << ": It is a B2-Sequence.\n";
        else
            cout << "Case #" << n++ << ": It is not a B2-Sequence.\n";
    }
    cout << '\n'; //you must add this, or else the system will verdict as WA or PE
}
