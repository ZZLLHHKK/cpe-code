#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mx = 200000;
vector<bool> prime1(mx + 1, true);
vector<int> prime2;

void seive() {
    prime1[0] = prime1[1] = false;
    for (int i = 2; i <= mx; ++i) {
        if (prime1[i]) {
            prime2.push_back(i);
            for (int j = 2 * i; j <= mx; j += i)
                prime1[j] = false;
        }
    }
}

int main() {
    int64_t n;
    seive();

    while (cin >> n && n != 0) {
        int d = 0, c = 1;
        bool b = false;
        map<int, int> cnt;
        while (prime2[d] * prime2[d] <= n && d < prime2.size()) {
            while (n % prime2[d] == 0) {
                cnt[prime2[d]]++;
                n /= prime2[d];
            }
            d++;
        }
        if (n > 1) cnt[n]++;
        for (auto &p : cnt) 
            c *= (p.second + 1);
        b = (c % 2 == 1);
        cout << (b == true ? "yes" : "no") << '\n';
    }
}

// another solution
// #include <iostream>
// #include <cmath>
// using namespace std;

// bool is_square(int64_t n) {
//     int64_t r = sqrt(n);
//     return r * r == n;
// }

// int main() {
//     int64_t n;
//     while (cin >> n && n != 0) {
//         cout << (is_square(n) ? "yes" : "no") << '\n';
//     }
// }
