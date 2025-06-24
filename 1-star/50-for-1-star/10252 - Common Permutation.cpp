#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string a, b;
    
    while (getline(cin, a) && getline(cin, b)) {
        vector<int> r(a.size(), 0), c(b.size(), 0);
        vector<char> ans;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if (a[i] == b[j] && r[i] == 0 && c[j] == 0) {
                    ans.push_back(a[i]);
                    r[i] = c[j] = 1;
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (char c : ans)
            cout << c;
        cout << '\n';
    }
}
