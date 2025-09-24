#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &n) {
    int s = (int)n.size();
    for (int i = 0, j = s - 1; i < (s / 2) && j >= (s / 2); ++i, --j) {
        if (n[i] != n[j])
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long cnt = 0, sum;
        string rev, num;
        cin >> num;
        do {
            cnt++;
            sum = 0;
            rev = num;
            reverse(rev.begin(), rev.end());
            sum = stol(num) + stol(rev);
            num = to_string(sum);
        } while (!isPalindrome(num));
        cout << cnt << " " << num << '\n';
    }
}
