#include <iostream>
using namespace std;
int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// 2011/1/1 Saturday
int main() {
    int t, a, b;
    cin >> t;
    
    while (t--) {
        int n = 6, dif = -1;
        cin >> a >> b;
        dif += b;
        for (int i = 0; i < a - 1; ++i)
            dif += mon[i];
        cout << day[(n + dif) % 7] << '\n';
    }
}
