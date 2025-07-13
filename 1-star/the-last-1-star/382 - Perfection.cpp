#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;

const string state[3] = {"DEFICIENT", "PERFECT", "ABUNDANT"};

int main() {
    int n;
    vector<pair<int, string>> ans;

    while (cin >> n && n) {
        int res = 0;
        vector<int> num;
        for (int i = 1; i <= (n / 2); ++i)
            if (!(n % i)) num.push_back(i);
        res = accumulate(num.begin(), num.end(), 0);
        if (res == n) ans.push_back(make_pair(n, state[1]));
        else if (res > n) ans.push_back(make_pair(n, state[2]));
        else ans.push_back(make_pair(n, state[0]));
    }

    cout << "PERFECTION OUTPUT\n";
    for (auto &p : ans) {
        cout << setw(5) << p.first << "  " << p.second << '\n';
    }
    cout << "END OF OUTPUT\n";
}
