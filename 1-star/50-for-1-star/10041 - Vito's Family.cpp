#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, num[30001] = {}, ans = 0;
        cin >> r;
        int mid = r / 2;
        for (int i = 0; i < r; ++i)
            cin >> num[i];
        sort(num, num + r);
        for (int j = 0; j < r; ++j)
            ans += abs(num[j]- num[mid]);
        cout << ans << '\n';
    }   
}
