#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<bool> prime(2001, true);
void seive() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < 2001; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < 2001; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    int t;
    seive();
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        int f = 1;
        string n;
        map<char, int> mp;
        cin >> n;
        for (int j = 0; j < n.size(); ++j)
            mp[n[j]]++;
        cout << "Case " << i << ": ";
        for (auto &p : mp) {
            if (prime[p.second]) {
                f = 0;
                cout << p.first;
            }
        }
        if (f) cout << "empty";
        cout << '\n';
    }
}
