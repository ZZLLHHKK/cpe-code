#include <iostream>
using namespace std;

int main() {
    string n;
    
    while (cin >> n && n[0] != '0') {
        while (n.size() != 1) {
            int tmp = 0;
            for (int i = 0; i < n.size(); ++i)
                tmp += n[i] - '0';
            n = to_string(tmp);
        }
        cout << n << '\n';
    }
}
