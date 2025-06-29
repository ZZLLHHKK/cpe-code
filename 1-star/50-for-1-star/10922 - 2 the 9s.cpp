#include <iostream>
using namespace std;

int main() {
    string n;

    while (cin >> n && n[0] != '0') {
        int cnt = 1, sum = 0, flag = 1;
        for (int i = 0; i < n.size(); ++i)
            sum += n[i] - '0';
        if (sum % 9 != 0) flag = 0;
        if (flag) {
            while (sum != 9) {
                int tmp = 0;
                while (sum != 0) {
                    tmp += sum % 10;
                    sum /= 10;
                }
                sum = tmp;
                cnt++;
            }
            cout << n << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
        }   
        else 
            cout << n << " is not a multiple of 9.\n";
    }
}
